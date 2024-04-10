#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e3+10;
const ll inf=1e18;
int ver[N][N],hor[N][N],n,m,k;

void read()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<m;j++) cin>>hor[i][j];
    for (int i=1;i<n;i++)
        for (int j=1;j<=m;j++) cin>>ver[i][j];
}

ll dp[22][N][N];

void opt(ll &x,ll y) {x=min(x,y);}

void process()
{
    if (k&1)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++) cout<<"-1 ";
            cout<<"\n";
        }
        return;
    }
    k/=2;
    for (int h=1;h<=k;h++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) dp[h][i][j]=inf;
    for (int h=1;h<=k;h++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (j>1) opt(dp[h][i][j],dp[h-1][i][j-1]+hor[i][j-1]);
                if (j<m) opt(dp[h][i][j],dp[h-1][i][j+1]+hor[i][j]);
                if (i>1) opt(dp[h][i][j],dp[h-1][i-1][j]+ver[i-1][j]);
                if (i<n) opt(dp[h][i][j],dp[h-1][i+1][j]+ver[i][j]);
            }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++) cout<<dp[k][i][j]*2<<" ";
        cout<<"\n";
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}