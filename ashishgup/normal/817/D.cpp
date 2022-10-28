//Stock Span Problem

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

ll n;
vll v;

vll calcspan()
{
	vll s(n);
	stack<ll> st;
	st.push(0);
	s[0]=1;
	for(ll i=1;i<n;i++)
	{
		while(!st.empty()&&v[st.top()]<v[i])
		{
			st.pop();
		}
		s[i]=st.empty()?(i+1):(i-st.top());
		st.push(i);
	}
	return s;
}

vll calcspan2()
{
	vll s(n);
	stack<ll> st;
	st.push(0);
	s[0]=1;
	for(ll i=1;i<n;i++)
	{
		while(!st.empty()&&v[st.top()]>v[i])
		{
			st.pop();
		}
		s[i]=st.empty()?(i+1):(i-st.top());
		st.push(i);
	}
	return s;
}

vll calcspan3()
{
	vll s(n);
	stack<ll> st;
	st.push(0);
	s[0]=1;
	for(ll i=1;i<n;i++)
	{
		while(!st.empty()&&v[st.top()]>=v[i])
		{
			st.pop();
		}
		s[i]=st.empty()?(i+1):(i-st.top());
		st.push(i);
	}
	return s;
}


vll calcspan4()
{
	vll s(n);
	stack<ll> st;
	st.push(0);
	s[0]=1;
	for(ll i=1;i<n;i++)
	{
		while(!st.empty()&&v[st.top()]<=v[i])
		{
			st.pop();
		}
		s[i]=st.empty()?(i+1):(i-st.top());
		st.push(i);
	}
	return s;
}

int main()
{
	IOS;
	cin>>n;
	v=vll(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	vll maxleft=calcspan();
	reverse(v.begin(),v.end());
	vll maxright=calcspan4();
	for(ll i=0;i<n;i++)
	{
		maxright[i]--;
	}
	reverse(v.begin(),v.end());
	reverse(maxright.begin(),maxright.end());
	vll minleft=calcspan2();
	reverse(v.begin(),v.end());
	vll minright=calcspan3();
	for(ll i=0;i<n;i++)
	{
		minright[i]--;
	}
	reverse(v.begin(),v.end());
	reverse(minright.begin(),minright.end());
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		ans+=(maxleft[i]*(maxright[i]+1)-(minleft[i])*(minright[i]+1))*v[i];
	}
	cout<<ans;
	return 0;
}