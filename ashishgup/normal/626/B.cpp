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

ll n;
char cache[201][201][201];
map<char,ll> m;

char dp(ll r, ll g, ll b)
{
	if(r<0)
	{
		return 'z';
	}
	if(g<0)
	{
		return 'z';
	}
	if(b<0)
	{
		return 'z';
	}
	if(cache[r][g][b]!='z')
	{
		//cout<<r<<" "<<g<<" "<<b<<endl;
		m[cache[r][g][b]]=1;
		return 'z';
	}
	//cout<<r<<" "<<g<<" "<<b<<endl;
	cache[r][g][b]='?';
	if(r>=2)
	{
		dp(r-1,g,b);
	}
	if(g>=2)
	{
		dp(r,g-1,b);
	}
	if(b>=2)
	{
		dp(r,g,b-1);
	}
	dp(r-1,g-1,b+1);
	dp(r-1,g+1,b-1);
	dp(r+1,g-1,b-1);
	return 'z';
}
int main()
{
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll r=0,g=0,b=0;
	for(ll i=0;i<201;i++)
	{
		for(ll j=0;j<201;j++)
		{
			for(ll k=0;k<201;k++)
			{
				cache[i][j][k]='z';
			}
		}
	}
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='R')
		{
			r++;
		}
		else if(s[i]=='G')
		{
			g++;	
		}
		else
		{
			b++;
		}
	}
 	cache[0][0][1]='B';
 	cache[0][1][0]='G';
 	cache[1][0][0]='R';
 	cache[0][0][0]='?';
	dp(r,g,b);
 	//cout<<m['R']<<" "<<m['G']<<" "<<m['B']<<endl;
 	if(m.find('B')!=m.end())
 	{
 		cout<<"B";
	}
	if(m.find('G')!=m.end())
 	{
 		cout<<"G";
	}
 	if(m.find('R')!=m.end())
 	{
 		cout<<"R";
	}
	return 0;
}