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

vector<ll> grundy;
int main()
{
    ll a,b;
    cin>>a>>b;
    vector<ll> ans;
    ans.push_back(b);
    bool check=true;
    while(b>a)
    {
    	if(b%2==0)
    	{
    		b=b/2;
		}
		else
		{
			if(b%10!=1)
			{
				check=false;
				break;
			}
			b=b/10;
		}
		ans.push_back(b);
	}
	if(b==a&&check)
	{
		cout<<"YES"<<endl;
		ll size=ans.size();
		cout<<size<<endl;
		for(ll i=size-1;i>=0;i--)
		{
			cout<<ans[i]<<" ";
		}
	}
	else
	{
		cout<<"NO";
	}
    return 0;
}