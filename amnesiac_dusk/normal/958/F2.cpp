#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pii pair<int , int>
#define pll pair<long long int,long long int>
#define mod 1000000007
#define inf 1e18+7
#define eps 0.00001
#define endl '\n'
inline bool check(ll a[],ll k[],ll n,ll m, ll p)
{
    int c[m];
    int nz=0;
    for(int i=0; i<m; i++)
    {
        c[i]=k[i];
        if(c[i]!=0)
            nz++;
    }
    for(ll i=0;i<p;i++)
    {
        c[a[i]]--;
        if(c[a[i]]==0)
            nz--;
    }
    if(nz==0)
    {
        return true;
    }
    for(ll i=p;i<n;i++)
    {
        c[a[i-p]]++;
        if(c[a[i-p]]==1)
            nz++;
        c[a[i]]--;
        if(c[a[i]]==0)
            nz--;
        if(nz==0)
            return true;
    }
    return false;
}
inline  ll bs(ll a[],ll k[],ll n,ll m)
{
    ll s=0,e=n,mid=(s+e)/2;
    while(s<e)
    {
        if(check(a,k,n,m,mid))
            e=mid;
        else
            s=mid+1;
        mid=(s+e)/2;
    }
    return e;
}
int main()
{
    srand(time(NULL));
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ll n,m;
    cin>>n>>m;
    ll a[n],k[m];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]--;
    }
    ll ans=0;
    for(ll i=0;i<m;i++)
    {
        cin>>k[i];
        ans+=k[i];
    }
    // int p;
    // cin>>p;
    // cout<<check(a,k,n,m,p)<<"\n";=0
    // int prefix[n+1][m] = {{0}};
    // for (int i = 1; i < n; ++i)
    // {
    //     prefix[i][a[i-1]-1]++;
    //     for(int j=0; j<m; j++)
    //     {
    //         prefix[i][j]+=prefix[i-1][j];
    //     }
    // }
    // int minv=1000000;
    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = i+1; j <= n; ++j)
    //     {
    //         bool pos=true;
    //         for(int l=0; l<m; l++)
    //         {
    //             if(k[l]>prefix[j][l]-prefix[i][l])
    //                 pos=false;
    //         }
    //         if(pos)
    //             minv=min(minv, j-i+1);
    //     }
    // }
    // if(bs(a,k,n,m)-ans!=minv-ans)
    // {
    //     cout<<n<<" "<<m<<"\n";
    //     for(int i=0; i<n; i++)
    //         cout<<a[i]<<" ";
    //     cout<<"\n";
    //     for(int i=0; i<m; i++)
    //         cout<<k[i]<<" ";
    //         cout<<endl;
    //     cout<<minv<<" "<<bs(a,k,n,m)-ans;
    // }
     if(!check(a,k,n,m,n))
         cout<<"-1";
     else
         cout<<bs(a,k,n,m)-ans;
}