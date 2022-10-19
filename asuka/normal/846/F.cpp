#include<bits/stdc++.h>
#define int long long
#define N 1000015
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
int n,a[N],nxt[N],pos[N],d[N],res,f[N],ans;
bool vis[N];
void add(int l,int r){
	res -= (r-l+1);
	d[l]--; d[r+1]++;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&n);
 	rep(i,1,n) scanf("%lld",&a[i]);
 	rep(i,1,n) pos[a[i]] = n+1;
 	per(i,1,n) nxt[i] = pos[a[i]],pos[a[i]] = i;
 	rep(i,1,n){
 		if(!vis[a[i]]) res++;
 		vis[a[i]] = 1;
 		f[i] = res;
 	}
 	res = 0;
 	rep(i,1,n) res += f[i];
 	// rep(i,1,n) printf("%lld ",f[i]); printf("\n");
 	rep(i,1,n) {
 		d[i] += d[i-1];
 		f[i] += d[i];
 		ans += f[i];
 		res -= f[i];
 		ans += res*2;
 		add(i+1,nxt[i]-1);
 	}
 	printf("%.10lf\n",((double) ans / ((double)n*n) ));
	return 0;
}
/*
3
1 4 1
*/