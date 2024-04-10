#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =2010;

ll n,a[N][N];

int main() 
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j){cout<<"0 ";continue;}
			ll ex=i+j+1;
			if(ex<=n-1){cout<<ex<<" ";continue;}
			ex-=n-1;
			if(i==n-1 || j==n-1){cout<<((ex+ex-1>n-1)?(ex+ex-1)%(n-1):ex+ex-1)<<" ";continue;}
			cout<<ex<<" ";
		}
		cout<<"\n";
	}
	return 0;
}