#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e14);
const ll MOD=((ll)94573);
const ll N =1001*1000;

ll n,m[20],r[20],p,ans;
bool mark[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	mark[0]=1;
	for(int i=0;i<n;i++)
	{
		cin>>m[i];
		if(p==0)p=m[i];
		else p=p*m[i]/__gcd(p,m[i]);	
	}
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
		for(int j=r[i];j<=p;j+=m[i])
			if(!mark[j])
				mark[j]=1,ans++;
	}
	cout<<fixed<<setprecision(12)<<(ld)(ans)/(p);
    return 0;
}