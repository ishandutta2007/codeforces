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
    IOS
    ll a,m;
    cin>>a>>m;
    vector<ll> v(m+1,0);
    while(true)
    {
    	if(v[0]>0)
    	{
    		break;
		}
		bool check=false;
		if(check)
		{
			break;
		}
		a=a%m;
		v[a]++;
		if(v[a]>1)
		{
		    break;
		}
		a=a+a%m;
		a=a%m;
	}
	if(v[0]>0)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}