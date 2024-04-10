#include<bits/stdc++.h>
#define int long long
#define N 100015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,a[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>t;
 	while(t--){
 		int ans = -inf;
 		cin>>n;
 		rep(i,1,n) cin>>a[i];
 		sort(a+1,a+n+1);
 		rep(i,1,n-4){
 			ans = max(ans,a[i]*a[i+1]*a[i+2]*a[i+3]*a[i+4]);
 		}
 		ans = max({ans,a[1]*a[2]*a[n]*a[n-1]*a[n-2],a[1]*a[2]*a[3]*a[4]*a[n]});
 		cout << ans << endl;
 	}
	return 0;
}