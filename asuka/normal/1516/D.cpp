#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
int n,q,a[N],nxt[N][22],low[N];
VI d[N];
int pri[N],tot,notp[N];
int vis[N];
void init(){
	memset(low,inf,sizeof low);
	low[1] = 1;
	rep(i,2,100000){
		if(!notp[i]) pri[++tot] = i,low[i] = i;
		for(int j = i+i;j <= 100000;j += i){
			notp[j] = 1;
			low[j] = min(low[j],i);
		}
	}
}
void ins(int p){
	for(auto u:d[p]) vis[u]++;
}
void del(int p){
	for(auto u:d[p]) vis[u]--;
}
bool check(int p){
	for(auto u:d[p]) if(vis[u]) return 0;
	return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	init();
 	scanf("%d%d",&n,&q);
 	rep(i,1,n) scanf("%d",&a[i]);
 	rep(i,1,n){
 		while(low[a[i]] > 1){
 			d[i].pb(low[a[i]]);
 			a[i] /= low[a[i]];
 		}
 		unique(all(d[i]));
 	}
 	int r = 0;
 	rep(i,1,n){
 		while(r+1 <= n){
 			if(check(r+1)) ins(++r);
 			else break;
 		}
 		nxt[i][0] = r+1;
 		del(i);
 	}
 	// rep(i,1,n) printf("%d ",nxt[i][0]); printf("\n");
 	rep(j,0,19) nxt[n+1][j] = n+1;
 	rep(j,1,19) {
 		rep(i,1,n) nxt[i][j] = nxt[nxt[i][j-1]][j-1];
 	}
 	while(q--){
 		int l,r,ans = 0;
 		scanf("%d%d",&l,&r);
 		per(i,0,19){
 			if(nxt[l][i] <= r) l = nxt[l][i],ans += (1<<i);
 		}
 		printf("%d\n",ans+1);
 	}
	return 0;
}