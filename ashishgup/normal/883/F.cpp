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

const int N=1e4+5;

string s;
set<string> ans;

void work()
{
	int sz=s.size();
	int check=0;
	s+='#';
	string cur;
	for(int i=0;i<sz;i++)
	{
		if(s[i]=='o'&&s[i+1]=='o')
		{
			cur+='u';
			i++;
			check=1;
		}
		else if(s[i]=='k'&&s[i+1]=='h')
		{
			cur+='h';
			i++;
			check=1;
		}
		else if(s[i]=='o'&&s[i+1]=='u')
		{
			cur+='u';
			cur+='o';
			i++;
			check=1;
		}
		else
		{
			cur+=s[i];
		}
	}
	s=cur;
	if(check)
		work();
}
int32_t main()
{
	int n;
	cin>>n;
	while(n--)
	{
		cin>>s;
		work();
		ans.insert(s);
	}
	cout<<ans.size();
}