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
    ll n,m,k;
    cin>>n>>m>>k;
    ll leftind=k;
    ll rightind=k;
    ll countleft=k-1;
    ll countright=n-k;
    ll pillows=m-n;
    ll store=1;
    ll ans=1;
    while(leftind>0&&rightind<=n&&pillows>0)
    {
    	pillows=pillows-store;
    	if(pillows>=0)
    	{
    		ans++;	
		}
    	leftind--;
    	rightind++;
    	if(leftind>0)
    	{
    		store++;
		}
		if(rightind<=n)
		{
			store++;
		}
	}
	while(leftind>0&&pillows>0)
    {
    	pillows=pillows-store;
    	if(pillows>=0)
    	{
    		ans++;	
		}
    	leftind--;
    	if(leftind>0)
    	{
    		store+=1;
		}
	}
	while(rightind<=n&&pillows>0)
    {
    	pillows=pillows-store;
    	if(pillows>=0)
    	{
    		ans++;	
		}
    	rightind++;
    	if(rightind<=n)
		{
			store+=1;
		}	
	}
	ans+=(pillows)/(n);
	cout<<ans;
    return 0;
}