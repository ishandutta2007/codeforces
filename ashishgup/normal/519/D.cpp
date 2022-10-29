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

typedef long long ll;

const long long N=1e5+5;

long long n;
long long val[26];
long long pref[N];
string s;

int main()
{
    IOS;
	for(long long i=0;i<26;i++)
	{
		cin>>val[i];
	}
	cin>>s;
	n=s.size();
	s='#'+s;
	for(long long i=2;i<=n;i++)
	{
		pref[i]=val[s[i]-'a'];
		pref[i]+=pref[i-1];
	}
	ll ans=0;
	for(char ch='a';ch<='z';ch++)
	{
		map<long long, long long> m;
		long long ct=0;
		for(long long i=1;i<=n;i++)
		{
			if(s[i]!=ch)
				continue;
			ct++;
			ans+=m[pref[i]-val[s[i]-'a']];
			m[pref[i]]++;
		}
	}
	cout<<ans;
	return 0;
}