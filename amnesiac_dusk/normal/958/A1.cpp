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
int a[20][20],x[20][20];
inline void rotate(ll n)
{
    int b[20][20];
    for(ll i=1;i<=n;i++)
    {
        int c[n+1];
        for(ll j=1;j<=n;j++)
        {
            c[j]=a[i][j];
        }
        for(ll j=1;j<=n;j++)
        {
            b[n-j+1][i]=c[j];
        }
    }
    for(ll i=0;i<20;i++)
    {
        for(ll j=0;j<20;j++)
            a[i][j]=b[i][j];
    }
}
inline void flipver(ll n)
{
    int b[20][20];
    for(ll i=1;i<=n;i++)
    {
        int c[n+1];
        for(ll j=1;j<=n;j++)
        {
            c[j]=a[i][j];
        }
        for(ll j=1;j<=n;j++)
        {
            b[n-i+1][j]=c[j];
        }
    }
    for(ll i=0;i<20;i++)
    {
        for(ll j=0;j<20;j++)
            a[i][j]=b[i][j];
    }
}
inline void fliphor(ll n)
{
    int b[20][20];
    for(ll j=1;j<=n;j++)
    {
        int c[n+1]={};
        for(ll i=1;i<=n;i++)
        {
            c[i]=a[i][j];
        }
        for(ll i=1;i<=n;i++)
        {
            b[i][n-j+1]=c[i];
        }

    }
    for(ll i=0;i<20;i++)
    {
        for(ll j=0;j<20;j++)
            a[i][j]=b[i][j];
    }
}
inline bool check(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(a[i][j]!=x[i][j])
                return false;
        }
    }
    return true;
}
int main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            char c;
            cin>>c;
            if(c=='X')
                x[i][j]=0;
            else
                x[i][j]=1;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            char c;
            cin>>c;
            if(c=='X')
                a[i][j]=0;
            else
                a[i][j]=1;
        }
    }
    ll t=6;
    while(t--)
    {
        if(check(n))
        {
            cout<<"Yes";return 0;
        }
        flipver(n);
        if(check(n))
        {
            cout<<"Yes";return 0;
        }
        flipver(n);
        fliphor(n);
        if(check(n))
        {
            cout<<"Yes";return 0;
        }
        fliphor(n);
        rotate(n);
        if(check(n))
        {
            cout<<"Yes";return 0;
        }
    }
    cout<<"No";return 0;
}