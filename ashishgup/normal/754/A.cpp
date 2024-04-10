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
	ll sum=0;
	bool checkzero=true;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
		if(v[i]!=0)
		{
			checkzero=false;
		}
	}
	if(checkzero)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	if(sum!=0)
	{
		cout<<"1"<<endl;
		cout<<"1"<<" "<<n;
		return 0;
	}
	else
	{
		ll i=0;
		for(;i<n;i++)
		{
			if(v[i]!=0)
			{
				break;
			}
		}
		i=i+1;
		cout<<"2"<<endl;
		cout<<"1"<<" "<<i<<endl;
		cout<<i+1<<" "<<n<<endl;
	}
	return 0;
}