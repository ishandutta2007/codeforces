/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

#define ll long long
#define pii pair <int,int>
#define pll pair <ll,ll>
#define fi first
#define se second
#define pb push_back

const int N=2e6+5;
const int mod=998244353;

map <ll,int> fc,num;

ll sqr(ll x) {
	ll y=sqrt(x);
	return y*y==x?y:0;
}

ll cbr(ll l,ll r,ll v){
	if(l==r)return (l*l*l==v?l:0);
	ll m=l+r>>1;
	return m*m*m>=v?cbr(l,m,v):cbr(m+1,r,v);
}

bool check(ll x) {
	ll y=sqr(x);
	if(y){
		ll z=sqr(y);
		z?fc[z]+=4:fc[y]+=2;
		return 1;
	}
	else{
		y=cbr(1,2e6,x);
		if(y) {fc[y]+=3; return 1;}
	} return 0;
}

ll n,a[N],ans=1;
vector <ll> buc;

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		ll x; cin>>x;
		if(!check(x)) {
			if(!num[x])buc.pb(x);
			num[x]++;
		}
	}
	for(int i=0;i<buc.size();i++)
		for(int j=i+1;j<buc.size();j++){
			ll x=__gcd(buc[i],buc[j]);
			if(x>1&&fc.find(x)==fc.end())fc[x]=0;
		}
	for(ll i:buc){
		int c=2,d=num[i];
		for(pll it:fc) if(i%it.fi==0) fc[it.fi]+=d,c--;
		ans=ans*(c==0?1:(c==1?d+1:(d+1)*(d+1)))%mod;
	}
	for(pll it:fc) ans=ans*(it.se+1)%mod;
	cout<<ans<<endl;
	
	return 0;
}