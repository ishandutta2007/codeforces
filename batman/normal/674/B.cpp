#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e14);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

ll n,k,a,b,c,d,id[N];


int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>a>>b>>c>>d;
	if(k==n-1 || k==n || n==4)return cout<<-1,0;
	
		id[1]=a;id[n]=b;id[2]=c;id[n-1]=d;
		cout<<a<<" "<<c<<" ";
		for(int i=3,j=1;i<=n-2;j++)
		{
			if(j==a || j==b || j==c || j==d)continue;
			id[i++]=j;
			cout<<j<<" ";
		}
		cout<<d<<" "<<b<<"\n";
	cout<<id[2]<<" "<<id[1]<<" ";
	for(int i=3;i<=n-2;i++)cout<<id[i]<<" ";
	cout<<id[n]<<" "<<id[n-1];
	return 0;
}