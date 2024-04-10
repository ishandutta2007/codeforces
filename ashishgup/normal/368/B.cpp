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

vector<ll> v;
vector<ll> cache(100002,0);
vector<ll> ans(100002,0);

ll dp(ll i)
{
	if(i<0)
	{
		return 0;
	}
	if(cache[v[i]]==0)
	{
		cache[v[i]]++;
		ans[i]=ans[i+1]+1;
	}
	else
	{
		ans[i]=ans[i+1];
	}
	return dp(i-1);
}
int main()
{
  	ll n,m;
  	cin>>n>>m;
  	v=vector<ll> (n);
  	for(ll i=0;i<n;i++)
  	{
  		cin>>v[i];
	}
	//cout<<"#";
	ll store=dp(n-1);
	//cout<<"#";
	vector<ll> q(m);
	//cout<<"#";
	for(ll i=0;i<m;i++)
	{
		cin>>q[i];
	}
	//cout<<"#";
	for(ll i=0;i<m;i++)
	{
		cout<<ans[q[i]-1]<<endl;
	}
	return 0;
}