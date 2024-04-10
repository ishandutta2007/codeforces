//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio(0);
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }


ll n,a[200*1000];
vector <ll> ans;

int Sa1378
{ 
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=n-1;i>0;i--)
    {
        if(a[i]==a[i-1] || a[i]==a[i-1]+1)
        {
            ans.push_back(a[i-1]);
            i--;    
        }
    }
    if(ans.size()<2)
        cout<<0;
    else    
    {
        ll sum=0;
        for(int i=0;i<ans.size()-1;i+=2)
            sum+=(ans[i]*ans[i+1]);
        cout<<sum;  
    }
        
    return 0;
}