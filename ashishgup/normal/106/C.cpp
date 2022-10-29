#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll> > vvll;

#define PI 3.141592653589793
#define MOD 1000000007

ll n,m;
ll cache[12][1002][1002];
vector<ll> a,b,c,d;

ll dp(ll i,ll count, ll c1)
{
	if(c1>n)
	{
		return -10000000;
	}
	if(i>m)
	{
		return 0;
	}
	ll cura=a[i]-count*b[i];
	if(cache[i][count][c1]!=-1)
	{
		return cache[i][count][c1];
	}
	if(cura<0)
	{
		cache[i][count][c1]=dp(i+1,1,c1);
		return cache[i][count][c1];
	}
	cache[i][count][c1]=Max(d[i]+dp(i,count+1,c1+c[i]),dp(i+1,1,c1),d[i]+dp(i+1,1,c1+c[i]));
	return cache[i][count][c1];
}
int main()
{
	cin>>n>>m;
	a=b=c=d=vector<ll> (m+1);
	a[0]=100;
	b[0]=0;
	ll c1,d1;
	cin>>c1>>d1;
	c[0]=c1;
	d[0]=d1;
	for(ll i=0;i<12;i++)
	{
		for(ll j=0;j<1002;j++)
		{
			for(ll k=0;k<1002;k++)
			{
				cache[i][j][k]=-1;
			}
		}
	}
	for(ll i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i];	
	}	
	ll ans=dp(0,1,0);
	cout<<ans;
	return 0;
}