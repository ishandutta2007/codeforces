#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (2100)
#define INF ((ll)1e14)
#define MOD ((ll)1e9+7)

ll x[3],y[3],xx,yy;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=0;i<3;i++)
	{
		cin>>x[i]>>y[i];
		for(int j=0;j<i;j++)
		{
			if(x[j]==x[i])xx++;
			if(y[j]==y[i])yy++;
		}	
	}
	if(xx==3 || yy==3)return cout<<1,0;
	if(xx==0 && yy==0)return cout<<3,0;
	if(x[0]!=x[1] && x[0]!=x[2])swap(x[0],x[2]),swap(y[0],y[2]);
	if(x[0]!=x[1])swap(x[1],x[2]),swap(y[1],y[2]);
	if(x[0]==x[1] && (y[2]<=min(y[0],y[1]) || y[2]>=max(y[0],y[1])))return cout<<2,0;
	if(y[0]!=y[1] && y[0]!=y[2])swap(x[0],x[2]),swap(y[0],y[2]);
	if(y[0]!=y[1])swap(x[1],x[2]),swap(y[1],y[2]);
	if(y[0]==y[1] && (x[2]<=min(x[0],x[1]) || x[2]>=max(x[0],x[1])))return cout<<2,0;
	cout<<3;
	
    return 0;
}