#include<bits/stdc++.h>
#define int long long
#define N 114514
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
using namespace std;
int t,n,c[N],a[N],b[N],f[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&t);
 	rep(_,1,t){
 		scanf("%lld",&n);
 		rep(i,1,n) scanf("%lld",&c[i]);
 		rep(i,1,n) scanf("%lld",&a[i]);
 		rep(i,1,n) scanf("%lld",&b[i]);
 		rep(i,1,n) f[i] = 0;
 		rep(i,2,n){
 			f[i] = (c[i]-1)+2+abs(a[i]-b[i]);
 			if(a[i] != b[i] && i > 2) f[i] = max(f[i-1]-abs(a[i]-b[i])+2+(c[i]-1),f[i]);
 		}
 		// rep(i,1,n) printf("%lld ",f[i]); printf("\n");
 		printf("%lld\n",*max_element(f+2,f+n+1));
 	}
	return 0;
}