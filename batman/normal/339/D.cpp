//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (1000*1000)
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


ll n,m,a[N];

int Sa1378
{ 
    IB
    cin>>n>>m;
    for(ll i=1ll;i<=tavan(2ll,n);i++)
        cin>>a[i];
    for(ll i=tavan(2ll,n)+1ll,first=1,j=i-1,k=0,p=0;j>=2;i++,k++)
    {
        if(p%2)
            a[i]=a[(((i-first+1)-j)*2)+first-1]^a[(((i-first+1)-j)*2)+first-2];
        else
            a[i]=a[(((i-first+1)-j)*2)+first-1]|a[(((i-first+1)-j)*2)+first-2]; 
        if(k==(j/2)-1)
        {
            first+=j;
            k=-1;
            j/=2;
            p++;
        }
    }
        
    for(ll i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        a[x]=y;
        for(ll j=tavan(2ll,n),first=1,k=x,q=0;j>=2;first+=j,j/=2,q++)
        {
            ll ex=k-first+1;
            if(ex%2)
                ex++,k++;   
            ex=(ex/2)+first+j-1;
            if(q%2)
                a[ex]=a[k]^a[k-1];
            else
                a[ex]=a[k]|a[k-1];
            k=ex;       
        }
        cout<<a[tavan(2ll,n+1)-1]<<"\n";
    }
    return 0;
}