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

int main()
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll possum=0;
    ll negsum=0;
    vector<ll> pos;
    vector<ll> neg;
    for(ll i=0;i<n;i++)
    {
    	cin>>v[i];
    	if(v[i]>0)
    	{
    		possum+=v[i];
    		pos.push_back(v[i]);
		}
		else
		{
			negsum+=v[i];
			neg.push_back(v[i]);
		}
	}
	ll ans=0;
	negsum*=-1;
	if(possum>negsum)
	{
		ans=1;
	}
	else if(possum<negsum)
	{
		ans=2;
	}
	else
	{
		ll size1=pos.size();
		ll size2=neg.size();
		ll min1=min(size1,size2);
		for(ll i=0;i<min1;i++)
		{
			neg[i]*=-1;
			if(pos[i]>neg[i])
			{
				ans=1;
				break;
			}
			else if(pos[i]<neg[i])
			{
				ans=2;
				break;
			}
		}
		if(ans==0)
		{
			if(size1<size2)
			{
				ans=2;
			}
			else if(size2<size1)
			{
				ans=1;
			}
		}
		if(ans==0)
		{
			if(v[n-1]>0)
			{
				ans=1;
			}
			else
			{
				ans=2;
			}
		}
	}
	if(ans==1)
	{
		cout<<"first";
	}
	else
	{
		cout<<"second";
	}
	return 0;
}