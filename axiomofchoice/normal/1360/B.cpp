#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=100010; typedef long long ll;
//#define int ll
int T,n,a[N];
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		repeat(i,0,n)cin>>a[i];
		sort(a,a+n);
		int ans=1e9;
		repeat(i,0,n-1)
			ans=min(ans,a[i+1]-a[i]);
		cout<<ans<<endl;
	}
	return 0;
}