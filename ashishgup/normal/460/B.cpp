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
    ll a,b,c;
    cin>>a>>b>>c;
    ll count=0;
    vector<ll> ans;
    for(ll i=1;i<=81;i++)
    {
        ll pow=1;
        for(ll j=1;j<=a;j++)
        {
            pow*=i;
        }
        ll check=b*pow+c;
        if(check>=1000000000)
        {
        	continue;
		}
		if(check<=0)
		{
			continue;
		}
        ll store=check;
        ll digsum=0;
        while(check>0)
        {
            int rem=check%10;
            digsum+=rem;
            check=check/10;
        }
        if(digsum==i)
        {
        	count++;
        	ans.push_back(store);
		}
    }
    cout<<count<<endl;
    for(ll i=0;i<count;i++)
    {
    	cout<<ans[i]<<" ";
	}
    return 0;
}