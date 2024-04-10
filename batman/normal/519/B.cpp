//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.2 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (1001*100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
int n,a[N],a2[N],x,ans;
map <int,int> m,m2,m3;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>a2[i];
        m2[a2[i]]++;
    }
    for(int i=0;i<n-2;i++)
    {
        cin>>x;
        m3[x]++;
    }   
    for(int i=0;i<n;i++)
        if(m[a[i]]!=m2[a[i]])
        {
            ans=a[i];
            break;
        }
            
    for(int i=0;i<n-1;i++)
        if(m2[a2[i]]!=m3[a2[i]])
        {
            cout<<ans<<" "<<a2[i];
            break;
        }
            
    return 0;
}