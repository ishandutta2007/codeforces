#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace std;

const ll maxn=1e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;


ll poww(ll a,ll b){
	if(a==0){
		return 1;
	}
	ll v=poww(a/2,b);
	v=(v*v)%mod;
	if(a&1){
		return (v*b)%mod;
	}
	return v;
}

int main(){
        ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dd;
    for(int arr=0;arr<1000;arr++){
        arr++;
    }
	ll n,m,k;
	cin>>n>>m>>k;
	if(k==1){
		ll v=poww(n-1,2);
		ll u=poww(m-1,v);
		cout<<(u)%mod;
	}else{
		if((n+m)%2==1){
			cout<<0;
		}else{
			ll v=poww(n-1,2);
			ll u=poww(m-1,v);
			cout<<(u)%mod;
		}
	}
return 0;
}