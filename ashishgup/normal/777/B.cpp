#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<pair<ll,ll> > > vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

int main()
{
	IOS;
	ll n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	vll f1(10,0);
	vll f2(10,0);
	for(ll i=0;i<n;i++)
	{
		int cha=a[i]-'0';
		int chb=b[i]-'0';
		f1[cha]++;
		f2[chb]++;
	}
	ll ans1=0;
	vll f2copy=f2;
	for(ll i=0;i<n;i++)
	{
		
			int ch1=a[i]-'0';
			bool check=false;
			for(ll j=ch1;j<=9;j++)
			{
				if(f2[j]>0)
				{
					check=true;
					f2[j]--;
					break;
				}
			}
			if(check)
				continue;
			for(ll j=0;j<=9;j++)
			{
				if(f2[j]>0)
				{
					f2[j]--;
					ans1++;
					break;
				}
			}
		
	}
	ll ans2=0;
	f2=f2copy;
	for(ll i=0;i<n;i++)
	{
			int ch1=a[i]-'0';
			bool check=false;
			for(ll j=ch1+1;j<=9;j++)
			{
				if(f2[j]>0)
				{
					f2[j]--;
					check=true;
					ans2++;
					//cout<<i<<" "<<j<<endl;
					break;
				}
			}
			if(check)
				continue;
			for(ll j=0;j<=9;j++)
			{
				if(f2[j]>0)
				{
					f2[j]--;
					break;
				}
			}
	}
	cout<<ans1<<endl<<ans2;
	return 0;
}