#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef vector<long long> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<pair<long long,long long> > vpll;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const long long N=1e6+5;

map<char, int> m1;
map<char, int> m2;
int main()
{
	IOS;
	string s,t;
	cin>>s>>t;
	ll a=s.size();
	ll b=t.size();
	for(int i=0;i<a;i++)
	{
		m1[s[i]]++;
	}
	for(int i=0;i<b;i++)
	{
		m2[t[i]]++;
	}
	int ans1=0,ans2=0;
	for(char ch='a';ch<='z';ch++)
	{
		int min1=min(m1[ch],m2[ch]);
		ans1+=min1;
		m1[ch]-=min1;
		m2[ch]-=min1;
	}
	for(char ch='A';ch<='Z';ch++)
	{
		int min1=min(m1[ch],m2[ch]);
		ans1+=min1;
		m1[ch]-=min1;
		m2[ch]-=min1;
	}
	for(char ch='a';ch<='z';ch++)
	{
		char ch2=ch-'a'+'A';
		int min1=min(m1[ch]+m1[ch2],m2[ch]+m2[ch2]);
		ans2+=min1;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}