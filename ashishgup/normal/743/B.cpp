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
typedef vector<vector<ll>> vvll;

#define PI 3.141592653589793
#define MOD 1000000007

int main()
{
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    if(k%2==1)
    {
        ans=1;
    }
    else
    {
        ll check=1;
        ll count=0;
        while(check<k)
        {
            check=check*2;
            count++;
        }
        if(check==k)
        {
            ans=count+1;
        }
        else
        {
            check=2;
            ans=2;
            while(((k-check)%(2*check))!=0)
            {
                ans++;
                check=check*2;
            }
        }
        
    }
    cout<<ans;
    return 0;
}