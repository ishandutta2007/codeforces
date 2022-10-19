#include<bits/stdc++.h>
#define int long long
#define N 100015
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
 		cin>>n;
 		int sum = 0,ans = 0;
 		rep(i,1,n) cin>>a[i];
 		reverse(a+1,a+n+1);
 		
 		rep(i,1,n){
 			if(a[i] > 0){
 				if(a[i] > sum) ans += a[i]-sum,sum = 0;
 				else sum -= a[i];
 			}else sum += -a[i];
 		}
 		cout << ans << endl;
 	}
	return 0;
}