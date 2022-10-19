#include<bits/stdc++.h>
#define ll long long
#define N ((1<<14)+10)
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,m,ans;
int a[N],cur[N],lst[N],cid[N],lid[N];
bool vis[N<<1];
char s[N];
namespace UF{
	VI lft;
	int fa[N<<1],siz[N<<1],tot;
	int find(int x){ return fa[x] == x?x:fa[x] = find(fa[x]);}
	int new_node(){
		if(lft.size() == 0){
			lft.pb(++tot);
			fa[tot] = tot; siz[tot] = 1;
			return new_node();
		}else{
			int u = lft.back();
			lft.pop_back();
			siz[find(u)]--;
			fa[u] = u; siz[u] = 1;
			return u;
		}
	}
	void del(int x){lft.pb(x);}
	void uni(int u,int v){
		u = find(u); v = find(v);
		if(u == v) return;
		if(siz[u] > siz[v]) swap(u,v);
		fa[u] = v; siz[v] += siz[u];
	}
}
using namespace UF;
void solve(char *s){
	rep(j,1,m/4) a[j] = (s[j]>='A'&&s[j]<='F'?s[j]-'A'+10:s[j]-'0');
	rep(j,1,m/4) rep(p,0,3)
		if((1<<p)&a[j]) cur[4*(j-1)+4-p] = 1;
		else cur[4*(j-1)+4-p] = 0;
	rep(j,1,m) cid[j] = new_node();
	rep(j,2,m) if(cur[j-1]&cur[j]) uni(cid[j-1],cid[j]);
	rep(j,1,m) if(cur[j]&lst[j]) uni(cid[j],lid[j]);
	// rep(i,1,m) printf("%d ",cur[i]);
	// printf("\n");
	// puts("Before");
	// rep(i,1,m) printf("%d ",cid[i]);
	// printf("\n");
	memset(vis,0,sizeof vis);
	rep(j,1,m){
		if(find(cid[j]) != cid[j] && !vis[cid[j]]) vis[cid[j]] = 1,del(cid[j]);
		cid[j] = find(cid[j]);
	}
	memset(vis,0,sizeof vis);
	rep(j,1,m){
		if(find(lid[j]) != lid[j] && !vis[lid[j]]) vis[lid[j]] = 1,del(lid[j]);
		lid[j] = find(lid[j]);
	}
	memset(vis,0,sizeof vis);
	rep(j,1,m) vis[cid[j]] = 1;
	rep(j,1,m) if(!vis[lid[j]]) vis[lid[j]] = 1,del(lid[j]),ans += lst[j];
	// puts("After");
	// rep(i,1,m) printf("%d ",cid[i]); printf("\n");
	swap(cid,lid); swap(cur,lst);
	// printf("ans: %d\n",ans);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,m) lid[i] = new_node();
	rep(i,1,n){
		scanf("%s",s+1);
		solve(s);
	}
	rep(i,1,m/4) s[i] = '0';
	solve(s);
	printf("%d\n",ans);
	return 0;
}
/*
0001
1010
1000
*/