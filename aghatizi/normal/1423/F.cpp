#include<bits/stdc++.h>

using namespace :: std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

const int  maxn=1e6+500;
const ll inf=1e16+900;

ll s[2];
int main(){
	ll n,k;
	ll su=0;
	cin>>n>>k;
	ll sm=0;
	for(int i=0;i<k;i++){
		ll a,b;
		cin>>a>>b;
		su+=b;
		sm+=(1LL*a*b)%n;
		sm%=n;
		s[a%2]+=b;
	}
	if(su>n){
		cout<<-1;
		return 0;
	}
	if(su<n){
		cout<<1;
		return 0;
	}
	ll smi=(n*(n-1))/2;
	smi%=n;
	if(sm==smi){
		cout<<1;
	}else{
		cout<<-1;
	}
	
	

}