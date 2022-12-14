#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define maxn 1000010
//#define mod 2147483647
#define int ll
//#define C 101
int n,k;
ll qpow(ll a,ll b,ll mod){
	ll ans=1;
	do{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}while(b>>=1);
	return ans;
}
int fac(int n,int c,int mod,const function<int(int)> &f){
	int p=c*c%mod,ans=0;
	for(int i=2;i*i<=n;i++){
		int cnt=0;
		while(n%i==0)n/=i,cnt++;
		ans=(ans+p*f(cnt))%mod;
		p=p*c%mod;
	}
	if(n>1)ans=(ans+qpow(c,n,mod)*f(1))%mod;
	return ans;
}
pii hash11(int n){
	return pii(
		fac(n,101,2147483647,[](int x){return x%k;}),
		fac(n,103,1000000007,[](int x){return x%k;})
	);
}
pii hash22(int n){
	return pii(
		fac(n,101,2147483647,[](int x){return (k-x%k)%k;}),
		fac(n,103,1000000007,[](int x){return (k-x%k)%k;})
	);
}
map<pii,int> m;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("data.txt","r",stdin);
	cin>>n>>k;
	int ans=0;
	repeat(i,0,n){
		int x;
		cin>>x;
		auto H11=hash11(x);
		auto H22=hash22(x);
		//cout<<x<<' '<<H11<<' '<<H22<<endl;
		if(m.count(H11))ans+=m[H11];
		m[H22]++;
	}
	cout<<ans<<endl;
	return 0;
}