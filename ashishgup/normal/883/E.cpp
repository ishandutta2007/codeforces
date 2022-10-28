#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=3e5+5;

int n, m;
string s;
string a[N];
set<char> revealed;
set<string> possible;

int check(char ch)
{
	int ct=0;
	for(auto it:possible)
	{
		int check=0;
		for(auto j:it)
		{
			if(j==ch)
			{
				check=1;
			}
		}
		ct+=check;
	}
	if(ct==possible.size())
		return 1;
	return 0;
}

int32_t main()
{
	cin>>n>>s>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]!='*')
		{
			revealed.insert(s[i]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int check=1;
		for(int j=0;j<n;j++)
		{
			if(s[j]!='*')
			{
				if(a[i][j]!=s[j])
				{
					check=0;
				}
			}
			else
			{
				if(revealed.find(a[i][j])!=revealed.end())
				{
					check=0;
				}
			}
		}
		if(check)
		{
			possible.insert(a[i]);
		}
	}
	int ans=0;
	for(char ch='a';ch<='z';ch++)
	{
		if(revealed.find(ch)!=revealed.end())
			continue;
		ans+=check(ch);
	}
	cout<<ans;
}