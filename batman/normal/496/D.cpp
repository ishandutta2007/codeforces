//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (100*1001)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){ll p=1ll;for(ll i=0;i<b;i++)p*=(ll)a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] < a[y]; }
ll n,chand[2][N],cnt[2][N],a[N],p[2]={1,1};
bool winer;
vector <pair <ll,ll> > ans;
void check(int t)
{
    bool mark=1;
    int i=0,j=0,p1=0,p2=0;
    while(mark)
    {
        mark=0;
        if(cnt[0][i+t]<cnt[1][j+t] && i+t<=n)
        {
            p1++;
            j=chand[1][cnt[0][i+t]];
            i+=t;
            mark=1;
        }
        else if(cnt[1][j+t]<cnt[0][i+t] && j+t<=n)
        {
            p2++;
            i=chand[0][cnt[1][j+t]];
            j+=t;
            mark=1;
        }
    }
    if(i+j==n && a[n-1]==1 && p1>p2)
        ans.push_back(MP(p1,t));
    if(i+j==n && a[n-1]==2 && p2>p1)
        ans.push_back(MP(p2,t));    
        
        
}

int Sa1378
{ 
    cin>>n;
    for(int i=0;i<=n;i++)
        cnt[1][i]=cnt[0][i]=1000*1000;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i!=0)
            chand[1][i]=chand[1][i-1],chand[0][i]=chand[0][i-1];
        chand[a[i]-1][i]++;
        cnt[a[i]-1][p[a[i]-1]]=i;
        p[a[i]-1]++;
        if(i==n-1)
            winer=a[i]-1;
    }   
    for(int i=1;i<=chand[winer][n-1];i++)
        check(i);
    cout<<ans.size()<<endl; 
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;   
    return 0;
}