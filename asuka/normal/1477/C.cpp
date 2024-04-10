#include<bits/stdc++.h>
#define int long long
#define N 5005
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
using namespace std;
int n,x[N],y[N];
bool vis[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&n);
	rep(i,1,n) scanf("%lld%lld",&x[i],&y[i]);
	int cur = 1; vis[cur] = 1;
	printf("%lld ",cur);
	rep(i,2,n){
		int mx = 0,mp = 0;
		rep(j,1,n){
			if(vis[j]) continue;
			int d = (x[j]-x[cur])*(x[j]-x[cur]) + (y[j]-y[cur])*(y[j]-y[cur]);
			if(d > mx) mx = d,mp = j;
		}
		printf("%lld ",mp);
		cur = mp; vis[cur] = 1;
	}
	return 0;
}