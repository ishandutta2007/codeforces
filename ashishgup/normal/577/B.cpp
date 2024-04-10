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
ll n,m;
vector<ll> v;
vector<vector<bool> >cache;
vector<vector<bool> >cache2;
ll dp(ll i,ll sum,ll count)
{
	sum=sum%m;
	if(sum%m==0&&count>=1)
	{
		//cout<<i<<" "<<sum<<endl;
		return true;
	}
	if(i>=n)
	{
		return false;
	}
	if(cache[i][sum]==false)
	{
		cache[i][sum]=true;
	}
	else
	{
		return cache2[i][sum];
	}
	cache2[i][sum]= dp(i+1,sum,count)||dp(i+1,sum+v[i],count+1);
	return cache2[i][sum];
}
int main()
{
  	cin>>n>>m;
  	v=vector<ll> (n);
  	for(ll i=0;i<n;i++)
  	{
  		cin>>v[i];
	}
	if(n>m)
	{
		cout<<"YES";
		return 0;
	}
  	cache=vector<vector<bool> > (n, vector<bool> (m,false));
  	cache2=vector<vector<bool> > (n, vector<bool> (m,false));
  	bool ans=dp(0,0,0);
  	if(ans)
  	{
  		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}