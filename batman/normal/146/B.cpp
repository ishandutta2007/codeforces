#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)

ll a,b,numb=1;

ll check(ll x)
{
	if(!x)return 0;
	if(x%10==4 || x%10==7)
		return check(x/10)*10+(x%10);
	return check(x/10);	
}


int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b;
	while(check(++a)!=b);
	cout<<a;
    return 0;
}