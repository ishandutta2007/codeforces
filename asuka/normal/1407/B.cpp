#include<bits/stdc++.h>
#define ll long long
#define N 1005
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,a[N],vis[N];
VI ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>t;
 	while(t--){
 		cin>>n;ans.clear();
 		rep(i,1,n) cin>>a[i],vis[i] = 0;
 		int lst = 0;
 		rep(i,1,n){
 			int res = 0,pos;
 			rep(j,1,n){
 				if(vis[j]) continue;
 				if(__gcd(lst,a[j]) > res){
 					res = __gcd(lst,a[j]);
 					pos = j;
 				}
 			}
 			//cout << i << ' ' << pos << endl;
 			vis[pos] = 1;
 			lst = __gcd(lst,res);
 			ans.pb(a[pos]);
 		}
 		rep(i,1,n) cout << ans[i-1] << ' ';
 		cout << endl;
 	}
	return 0;
}