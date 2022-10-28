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
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;
typedef long double ld;
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

bool check(vll v)
{
	ld med=(ld)v[1]/2 + (ld)v[2]/2;
	ld mean=v[0]+v[1]+v[2]+v[3];
	mean/=4;
	ld range=v[3]-v[0];
	vll v2=v;
	sort(v2.begin(),v2.end());
	if(med==mean&&mean==range&&v==v2)
	{
		return true;
	}
	return false;
}
int main()
{
	IOS;
	ll n;
	ll sum=0;
	cin>>n;
	if(n==0)
	{
		cout<<"YES"<<endl;
		cout<<"1\n1\n3\n3";
		return 0;
	}
	vll v(4,-1);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	if(n==1)
	{
		ll a=v[0];
		cout<<"YES"<<endl;
		cout<<2*a<<endl<<2*a<<endl<<3*a;
		return 0;
	}
	if(n==4)
	{
		sort(v.begin(),v.end());
		if((v[1]+v[2])%2!=0)
		{
			cout<<"NO";
			return 0;
		}
		ll median=(v[1]+v[2])/2;
		bool check=true;
		if(v[3]-v[0]!=median)
			check=false;
		if(sum!=median*n)
		{
			check=false;
		}
		if(check)
		{
			cout<<"YES";
			return 0;
		}
		else
		{
			cout<<"NO";
			return 0;
		}
	}
	if(n==2)
	{
		sort(v.begin(),v.begin()+2);
		//trace1(v[0]);
		v[2]=4*v[0]-v[1];
		v[3]=3*v[0];
		vll v2=v;
		sort(v2.begin(),v2.end());
		if(v[2]<=0)
		{
			cout<<"NO";
			return 0;
		}
		cout<<"YES"<<endl;
		cout<<v[2]<<endl<<v[3];
		return 0;
	}
	ll sz=v.size();
	sort(v.begin(),v.end());
	//cout<<"J";
	do
	{
	/*	for(auto it:v)
		{
			cout<<it<<" ";
		}
		cout<<endl;*/
		for(ll i=0;i<4;i++)
		{
			if(v[i]==-1)
			{
				for(ll j=1;j<=5000;j++)
				{
					v[i]=j;
					bool check1=check(v);
					if(check1)
					{
						cout<<"YES"<<endl<<j;
						return 0;
					}
				}
				v[i]=-1;
			}
		}
	}while(next_permutation(v.begin(),v.end()));
	cout<<"NO";
	return 0;
}