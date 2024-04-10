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

ll sumdigits(ll x)
{
	ll sum=0;
	while(x>0)
	{
		ll rem=x%10;
		sum+=rem;
		x=x/10;
	}
	return sum;
}

ll solvequad(ll a,ll b,ll c)
{
	long double D=b*b-4*a*c;
	long double ans=0;
	if(D<=0)
	{
		return -1;
	}
	else
	{
		ans=(-(long double)b+sqrt(D))/(2.0*(long double)a);
	}
	if(ceil(ans)==floor(ans))
	{
		ll ans2=ans;
		return ans2;
	}
	else
	{
		return -1;
	}
}
int main()
{
  	ll n;
  	cin>>n;
  	bool check1=false;
  	vector<ll> ans;
  	for(ll i=0;i<=90;i++)
  	{
  		ll check=solvequad(1,i,-1*n);
		if(check==-1)
		{
			continue;
		}
		if(sumdigits(check)==i)
		{
			check1=true;
			ans.push_back(check);
		}	
	}
	if(check1==false)
	{
		cout<<"-1";
		return 0;
	}
	sort(ans.begin(),ans.end());
	cout<<ans[0];
	return 0;
}