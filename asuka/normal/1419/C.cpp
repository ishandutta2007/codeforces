#include<bits/stdc++.h>
#define int long long
#define N 1005
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
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
 		int ans = inf,cur,ff = 0;
 		cin>>n>>cur;
 		rep(i,1,n) cin>>a[i];
 		int sum = 0;rep(i,1,n) sum += a[i];
 		rep(i,1,n) if(a[i] == cur) ff++;
 		if(n*cur == sum) ans = min(ans,1ll);
 		if(ff == n) ans = min(ans,0ll);
 		if(ff > 1){
 			ans = min(ans,1ll);
 		}else{
 			ans = min(ans,2ll);
 		}
 		int left = n-ff;
 		if(left < n) ans = min(ans,1ll);
 		if(sum%n == 0){
 			if(ff) ans = min(ans,1ll);
 		}
 		cout << ans << endl;
 	}
	return 0;
}