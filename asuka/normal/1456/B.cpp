#include<bits/stdc++.h>
#define int long long
#define N 100015
#define D 100
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
int n,a[N],pre[N],p[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&n);
 	rep(i,1,n) scanf("%lld",&a[i]);
 	rep(i,1,n) pre[i] = pre[i-1]^a[i];
 	int ans = inf;
 	if(n > 100) ans = 1;
 	else {
 		rep(l,1,n){
 			rep(p,l,n){
 				rep(r,p+1,n){
 					if((pre[p]^pre[l-1])>(pre[p]^pre[r])) ans = min(ans,r-l-1);
 				}
 			}
 		}
 	}
 	printf("%lld\n",ans==inf?-1:ans);
	return 0;
}