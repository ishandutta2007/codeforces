//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (501*1001)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] < a[y]; }
ll n,a[N],lastp[N],point;
bool mark[N];
pair <ll,ll> ans[N];

void erat()
{
    for(int i=2;i<=N;i++)
        if(mark[i]==0)
            for(int j=2*i;j<=N;j+=i)
                mark[j]=true;
}
void prp()
{
    lastp[2]=2;
    for(int i=3;i<=N;i++)
    {
        if(mark[i]==false)
            lastp[i]=i;
        else
            lastp[i]=lastp[i-1];    
    }   
}

int Sa1378
{ 
    erat();
    prp();
    //chie(lastp[100]);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    point=0;    
    for(int i=1;i<=n;i++)
    {
        ll num=a[i];
        if(num>i)
        {
            for(int j=i;j<num;)
            {
                ll ex=num-j+1,last=j;
                j+=lastp[ex]-1;
                swap(a[last],a[j]);
                ans[point]={last,j};
                point++;
            }
            i--;    
        }
    }   
    cout<<point<<endl;
    for(int i=0;i<point;i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;   
    return 0;
}