#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
#define int ll
int n,a[N],ans;
void solve(){
	cin>>n; ans=n;
	repeat(i,0,n)cin>>a[i];
	repeat(i,1,n-1)
	if((a[i-1]-a[i])*(a[i]-a[i+1])>0)
		ans--;
	cout<<ans<<endl;
	cout<<a[0]<<' ';
	repeat(i,1,n-1)
	if((a[i-1]-a[i])*(a[i]-a[i+1])<=0)
		cout<<a[i]<<' ';
	cout<<a[n-1]<<endl;
}
signed main(){
	int T; cin>>T;
	while(T--){
		solve();
	}
	return 0;
}