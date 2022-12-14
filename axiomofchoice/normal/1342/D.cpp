#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll;
#define int ll
int a[N],c[N];
int n,k,ans;
signed main(){
	cin>>n>>k;
	repeat(i,1,n+1)cin>>a[i]; sort(a+1,a+n+1);
	repeat(i,1,k+1)cin>>c[i];
	repeat(i,1,n+1)ans=max(ans,(n-i+1+c[a[i]]-1)/c[a[i]]);
	cout<<ans<<endl;
	repeat(i,1,ans+1){
		int cnt=0;
		for(int j=i;j<=n;j+=ans)
			cnt++;
		cout<<cnt<<' ';
		for(int j=i;j<=n;j+=ans)
			cout<<a[j]<<' ';
		cout<<endl;
	}
	return 0;
}