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

char v[4][4];

bool check(ll a,ll b)
{
	bool ans=false;
	for(ll j=0;j<=1;j++)
	{
		if(v[a][j]=='x'&&v[a][j+1]=='x'&&v[a][j+2]=='x')
		{
			ans=true;
		}
	}
	for(ll j=0;j<=1;j++)
	{
		if(v[j][b]=='x'&&v[j+1][b]=='x'&&v[j+2][b]=='x')
		{
			ans=true;
		}
	}
	ll lrd=1;
	ll rrd=1;
	if(a>=1&&b>=1&&v[a-1][b-1]=='x')
	{
		lrd++;
	}
	if(a<=2&&b<=2&&v[a+1][b+1]=='x')
	{
		rrd++;
	}
	if(lrd==2&&rrd==2)
	{
		ans=true;
	}
	if(a<=1&&b<=1&&v[a+2][b+2]=='x')
	{
		rrd++;
	}
	if(a>=2&&b>=2&&v[a-2][b-2]=='x')
	{
		lrd++;
	}
	if(lrd==3||rrd==3)
	{
		ans=true;
	}
	ll lld=1;
	ll rld=1;
	if(a<=2&&b>=1&&v[a+1][b-1]=='x')
	{
		lld++;
	}
	if(a>=1&&b<=2&&v[a-1][b+1]=='x')
	{
		rld++;
	}
	if(lld==2&&rld==2)
	{
		ans=true;
	}
	if(a>=2&&b<=1&&v[a-2][b+2]=='x')
	{
		rld++;
	}
	if(a<=1&&b>=2&&v[a+2][b-2]=='x')
	{
		lld++;
	}
	if(lld==3||rld==3)
	{
		ans=true;
	}
	return ans;
}

int main()
{
	for(ll i=0;i<4;i++)
	{
		for(ll j=0;j<4;j++)
		{
			cin>>v[i][j];
		}
	}
	bool check1=false;
	for(ll i=0;i<4;i++)
	{
		if(check1==true)
		{
			break;
		}
		for(ll j=0;j<4;j++)
		{
			if(v[i][j]!='.')
			{
				continue;
			}
			else
			{
				//cout<<i<<" "<<j<<endl;
				v[i][j]='x';
				check1=check(i,j);
				if(check1==true)
				{
					break;
				}
				v[i][j]='.';
			}
		}
	}
	if(check1)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}