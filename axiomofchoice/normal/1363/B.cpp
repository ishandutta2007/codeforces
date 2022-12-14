#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll;
#define int ll
int T,n,sum[N];
string s;
int q1(int l,int r){
	return sum[r]-sum[l-1];
}
int q0(int l,int r){
	return r-l+1-q1(l,r);
}
signed main(){
	cin>>T;
	while(T--){
		cin>>s; s='x'+s; 
		int n=s.size()-1;
		repeat(i,1,n+1)
			sum[i]=sum[i-1]+(s[i]=='1');
		int ans=1e9;
		repeat(i,0,n+1){
			//cout<<i<<' '<<q0(1,i)+q1(i+1,n)<<' '<<q1(1,i)+q0(i+1,n)<<endl;
			ans=min(ans,q0(1,i)+q1(i+1,n));
			ans=min(ans,q1(1,i)+q0(i+1,n));
		}
		cout<<ans<<endl;
	}
	return 0;
}