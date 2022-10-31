//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2 ///////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(int x){for(int i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}

ifstream fin("input.txt");
ofstream fout("output.txt");
ll a[3],in[3],ans[3];
bool sortt(int x,int y){ return a[x] < a[y]; }
int Sa1378
{ 
    cin>>a[0]>>a[1]>>a[2];
    in[1]=1;
    in[2]=2;
    sort(in,in+3,sortt);
    
    int x=a[in[2]]-a[in[0]]-a[in[1]];
    if(x>0 || x%2)
    {
        cout<<"Impossible";
        return 0;
    }
    if(x==0)
    {
        int ex=in[2];
        if(ex==0)
        {
            ans[0]=a[1];
            ans[2]=a[2];
        }
        if(ex==1)
        {
            ans[1]=a[2];
            ans[0]=a[0];
        }
        if(ex==2)
        {
            ans[1]=a[1];
            ans[2]=a[0];
        }
    }
    else
    {
        int ex=in[2];
        x*=(-1);
        x/=2;
        if(ex==0)
        {
            ans[0]=a[1]-x;
            ans[2]=a[2]-x;
            ans[1]=x;
        }
        if(ex==1)
        {
            ans[1]=a[2]-x;
            ans[0]=a[0]-x;
            ans[2]=x;
        }
        if(ex==2)
        {
            ans[0]=x;
            ans[1]=a[1]-x;
            ans[2]=a[0]-x;
        }
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
    
    
    return 0;
}