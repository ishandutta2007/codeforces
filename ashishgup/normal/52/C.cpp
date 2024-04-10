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
vll lo,hi,min1,delta;

void initialise(ll i,ll a, ll b)
{
	lo[i]=a;
	hi[i]=b;
	if(a==b)
		return;
	ll m=(a+b)/2;
	initialise(2*i,a,m);
	initialise(2*i+1,m+1,b);
}

void prop(ll i)
{
	delta[2*i]+=delta[i];
	delta[2*i+1]+=delta[i];
	delta[i]=0;
}

void update(ll i)
{
	min1[i]=min(min1[2*i]+delta[2*i],min1[2*i+1]+delta[2*i+1]);
}
void increment(ll i,ll a, ll b,ll k)
{
	if(b<lo[i]||hi[i]<a)
	{
		return;
	}
	if(a<=lo[i]&&hi[i]<=b)
	{
		delta[i]+=k;
		return;
	}
	prop(i);
	increment(2*i,a, b, k);
	increment(2*i+1,a, b, k);
	update(i);
}

ll minimum(ll i, ll a, ll b)
{
	if(hi[i]<a||lo[i]>b)
	{
		return LLONG_MAX;
	}
	if(a<=lo[i]&&hi[i]<=b)
	{
		return min1[i]+delta[i];
	}
	prop(i);
	ll minleft=minimum(2*i,a,b);
	ll minright=minimum(2*i+1,a,b);
	update(i);
	return min(minleft,minright);
}
int main()
{
	IOS;
	cin>>n;
	lo.resize(4*n+1);
	hi.resize(4*n+1);
	min1.resize(4*n+1,0);
	delta.resize(4*n+1,0);
	initialise(1,0,n-1);
	for(ll i=0;i<n;i++)
	{
		ll k;
		cin>>k;
		increment(1, i, i, k);	
	}
	ll m;
	cin>>m;
	string s;
	getline(cin,s);
	vector<ll> output;
	for(ll i=0;i<m;i++)
	{
		getline(cin,s);
		ll sz=s.size();
		stringstream ss(s);
		vector<ll> v;
		ll num;
		while(!ss.eof())
		{
			ss>>num;
			v.pb(num);
		}
		sz=v.size();
		if(sz==2)
		{
			ll a=v[0];
			ll b=v[1];
			if(b>=a)
			{
				output.pb(minimum(1,a,b));
			}
			else
			{
				ll pos1=minimum(1,0,b);
				ll pos2=minimum(1,a,n-1);
				output.pb(min(pos1,pos2));
			}
		}
		else
		{
			ll a=v[0],b=v[1],c=v[2];
			if(b>=a)
			{
				increment(1,a,b,c);
			}
			else
			{
				increment(1,0,b,c);
				increment(1,a,n-1,c);
			}
		}
	}
	ll sz=output.size();
	for(ll i=0;i<sz;i++)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}