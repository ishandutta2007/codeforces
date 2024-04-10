#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(ll i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
ll ans=1,x,n;
const ll mod=1000000007;
void p(ll x){ans=(ans*x)%mod;}
void po(ll a,ll b){
	do{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}while(b>>=1);
}
void caozuo(ll xx,ll n){
	while(1){
		po(xx,n/xx);
		n/=xx;
		if(n==0)return;
	}
	for(ll i=xx;;){
		if(n<i)return;
		po(xx,n/i);
		if(i>n/xx)return;
		i*=xx;
	}
}
int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>x>>n;
	repeat(i,2,(int)sqrt(x)+2)
	if(x%i==0){
		//cout<<i<<endl;
		caozuo(i,n);
		while(x%i==0)x/=i;
	}
    if(x>1)caozuo(x,n);
	cout<<ans<<endl;
	return 0;
}