#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define B 731
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
int n,x,dep[N],k[N],cnt[N],lef[N],md;
bitset<N> f[B];
int m;
bool gkp[N];
int islf[N],cho[N];
VI e[N],ver[N],tmp,in[N];
map<int,int> M;
void dfs(int u,int fa){
	bool flag = 0;
	dep[u] = dep[fa]+1; md = max(md,dep[u]);
	ver[dep[u]].pb(u);
	for(auto v:e[u]) if(v != fa){
		dfs(v,u); flag = 1;
	}
	if(!flag) lef[dep[u]]++,islf[u] = 1;
}
void get(int a,int b){
	if(b == 0) return;
	for(auto u:in[a]){
		if(cnt[a] > b || f[a-1][b]) break;
		b -= cnt[a], gkp[u] = 1;
	}
	get(a-1,b);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&x);
 	rep(i,2,n){
 		int v; scanf("%d",&v);
 		e[v].pb(i); e[i].pb(v);
 	}
 	dfs(1,0);
 	rep(i,1,md) tmp.pb(SZ(ver[i]));
 	sort(all(tmp)); tmp.erase(unique(all(tmp)),tmp.end()); m = SZ(tmp);
 	rep(i,1,m) M[tmp[i-1]] = i,cnt[i] = tmp[i-1];
 	rep(i,1,md) k[M[SZ(ver[i])]]++,in[M[SZ(ver[i])]].pb(i);
 	// ver[i]: vertices in depth i
 	// in[i] : layers of ith largest size
 	f[0][0] = 1;
 	rep(i,1,m){
 		f[i] = f[i-1]; int sz = k[i];
 		for(int j = 1; j <= sz;j <<= 1){
 			sz -= j; f[i] |= (f[i] << (j*cnt[i]));
 		}
 		if(sz > 0) f[i] |= (f[i] << (sz*cnt[i]));
 	}
 	if(f[m][x]){
 		printf("%d\n",md);
 		get(m,x);
 		rep(i,1,n){
 			putchar(gkp[dep[i]]?'a':'b');
 		}
 		return 0;
 	}
 	int ans = 0;
 	rep(i,0,x) if(f[m][i]) ans = i;
 	// if(md+1 == 28) puts("Two");
 	printf("%d\n",md+1);
 	get(m,ans);
 	int pos = 0,Max = 0;
 	rep(i,1,md){
 		if(!gkp[i]){
 			if(lef[i] > Max) Max = lef[i],pos = i;
 		}
 	}
 	int lft = x-ans;
 	assert(Max >= lft);
 	assert(lef[pos] == Max);
 	for(auto u:ver[pos]){
 		if(!lft) break;
 		if(islf[u] == 1) lft--,cho[u] = 1;
 	}
 	int ccnt = 0,acnt = 0;
 	rep(i,1,n){
 		if(gkp[dep[i]]) putchar('a'),acnt++;
 	    else if(cho[i] == 1) putchar('a'),ccnt++;
 		else putchar('b');
 	}
 	// if(md==27) printf("%d%d\n",acnt,ccnt);
	return 0;
}