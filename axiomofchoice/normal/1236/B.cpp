#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
int mod=1000000007;
ll qpow(ll a,ll b/*,ll mod*/){
	ll ans=1;
	do{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}while(b>>=1);
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n,m,ans=1;
	cin>>n>>m;
	ans=qpow((qpow(2,m)-1+mod)%mod,n);
	cout<<ans<<endl;
	return 0;
}