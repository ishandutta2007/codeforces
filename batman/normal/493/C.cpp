//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (500*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}

ll n,m,num[2],maxans,maxnum[2];
pair <ll,bool> p[N];
int main()
{ 
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].first;
    cin>>m;
    for(int i=n;i<m+n;i++)
    {
        cin>>p[i].first;
        p[i].second=1;
    }
    sort(p,p+n+m);
    for(int i=0;i<n+m;i++)
    {
        num[p[i].second]++;
        if(num[1]-num[0]>maxans)
        {
            maxans=num[1]-num[0];
            maxnum[1]=num[1];
            maxnum[0]=num[0];
        }
    }
    ll ans1=maxnum[0]*2+(n-maxnum[0])*3,ans2=maxnum[1]*2+(m-maxnum[1])*3;
    cout<<ans1<<":"<<ans2;
    return 0;
}