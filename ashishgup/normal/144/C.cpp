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

map<char,int> m1,m2;

bool check()
{
	int ques=m1['?'];
	bool ans=true;
	for(auto it:m2)
	{
		char ch=it.ff;
		int occ=it.ss;
		int occ2=m1[ch];
		if(occ2>occ)
		{
			ans=false;
			break;
		}
		if(occ>occ2)
		{
			int diff=occ-occ2;
			if(ques<diff)
			{
				ans=false;
				break;
			}
			ques-=diff;
		}
	}
	return ans;
}
int main()
{
	IOS;
	string a,b;
	cin>>a>>b;
	int len1=a.size();
	int len2=b.size();
	for(int i=0;i<len2;i++)
	{
		m2[b[i]]++;
	}
	int i;
	for(i=0;i<len2;i++)
	{
		m1[a[i]]++;
	}
	ll ans=0;
	ans+=check();
	while(i<len1)
	{
		m1[a[i]]++;
		m1[a[i-len2]]--;
		ans+=check();
		i++;
	}
	cout<<ans;
	return 0;
}