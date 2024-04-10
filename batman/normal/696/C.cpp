#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,n/=2,a*=a,a%=mod;return res;}
const ll N=((ll)101*1000);
const ll INF=((ll)2e18);
const ll MOD=((ll)1e9+7);

ll n,mat[2][2],ex[2][2];

void tavan(ll x)
{
	ex[0][0]=1;ex[0][1]=0;
	ex[1][0]=0;ex[1][1]=1;
	while(x)
	{
		if(x%2)
		{
			ll ex2[2][2]={};
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					for(int k=0;k<2;k++)
						ex2[i][j]+=ex[i][k]*mat[k][j],ex2[i][j]%=MOD;
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					ex[i][j]=ex2[i][j];
		}
		ll ex2[2][2]={};
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					ex2[i][j]+=mat[i][k]*mat[k][j],ex2[i][j]%=MOD;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				mat[i][j]=ex2[i][j];
		x/=2;
		//cout<<x<<"\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	mat[0][0]=1;mat[0][1]=2;
	mat[1][0]=1;
	ll num=2;
	bool mark=1;
	while(n--)
	{
		ll x;
		cin>>x;
		if(x!=1)mark=0;
		num=tavan(num,x,MOD);
		//cout<<x<<"\n";
		tavan(x);
		
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				mat[i][j]=ex[i][j];
	}
	ll ans=mat[0][0]-mat[1][0]+MOD;
	ans%=MOD;
	ans*=tavan(2,MOD-2,MOD);ans%=MOD;
	if(mark)return cout<<"0/1",0;
	num*=tavan(2,MOD-2,MOD);
	cout<<ans<<"/"<<num%MOD<<"\n";
    return 0;
}