//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (2200)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
int n,a[N],index[N],ans;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool sortt(int x,int y){ return a[x] < a[y]; }

int Sa1378
{ 
    cin>>n; 
    for(int i=1;i<=n;i++)
        cin>>a[i],index[i]=i;
    sort(index+1,index+n+1,sortt);
    for(int i=1;i<n;i++)
        if(a[index[i]]==a[index[i+1]])
            ans++;
    if(ans<=1)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;;
    for(int i=1;i<=n;i++)
        cout<<index[i]<<" ";
    cout<<endl;
    ans=1;
    for(int i=1;i<n && ans<3;i++)
    {
        if(a[index[i]]==a[index[i+1]])
        {
            swap(index[i],index[i+1]);
            ans++;
            for(int j=1;j<=n;j++)
                cout<<index[j]<<" ";
            cout<<endl; 
        }
        
    }       
    return 0;
}