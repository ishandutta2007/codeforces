#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=100010; typedef long long ll;
//#define int ll
int T,n,k;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		int ans=1e9;
		for(int i=1;i*i<=n;i++)
		if(n%i==0){
			if(i<=k)ans=min(ans,n/i);
			if(n/i<=k)ans=min(ans,i);
		}
		cout<<ans<<endl;
	}
	return 0;
}