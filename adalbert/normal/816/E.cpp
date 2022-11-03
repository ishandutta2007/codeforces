#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define pb push_back
typedef long long ll;
typedef long double ld;
const int arr=300000+10;

int dp[5002][5002][2],a[6000],sum[6000],n,k,c[6000],d[6000];

vector<int> vec[5100];

void getsum(int u)
{
    sum[u]=1;
    for (int i=0;i<vec[u].size();i++)
    {
        getsum(vec[u][i]);
        sum[u]+=sum[vec[u][i]];
    }
}

bool check(int i, int j)
{
    return(sum[i]<sum[j]);
}

void get1(int u)
{
    dp[u][1][1]=c[u]-d[u];
    int siz=1;
    vector<int> sons;
    for (int i=0;i<vec[u].size();i++)
        sons.pb(vec[u][i]);
    sort(sons.begin(),sons.end(),check);

    for (int i=0;i<sons.size();i++)
    {
        int to=sons[i];
        for (int j=siz;j>=0;j--)
            for (int k=0;k<=sum[to];k++)
            dp[u][j+k][1]=min(dp[u][j+k][1],dp[u][j][1]+min(dp[to][k][1],dp[to][k][0]));
        siz+=sum[to];
    }

}
void get0(int u)
{
    dp[u][0][0]=0;
    dp[u][1][0]=c[u];
    int siz=1;
    vector<int> sons;
    for (int i=0;i<vec[u].size();i++)
        sons.pb(vec[u][i]);
    sort(sons.begin(),sons.end(),check);
    for (int i=0;i<sons.size();i++)
    {
        int to=sons[i];
        for (int j=siz;j>=0;j--)
            for (int k=0;k<=sum[to];k++)
            if (j+k<=n)
            {
                dp[u][j+k][0]=min(dp[u][j+k][0],dp[u][j][0]+dp[to][k][0]);
            }
        siz+=sum[to];
    }
}

void dfs(int u)
{
    for (int i=0;i<vec[u].size();i++)
        dfs(vec[u][i]);
    if (vec[u].empty())
    {
        dp[u][0][0]=0;
        dp[u][1][0]=c[u];
        dp[u][1][1]=c[u]-d[u];
        return;
    }
    get1(u);
    get0(u);

}

signed main()
{
    fast;
    cin>>n>>k;
    cin>>c[1]>>d[1];
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
        {
            dp[i][j][0]=1e9+10;
            dp[i][j][1]=1e9+10;
        }

    for (int i=2;i<=n;i++)
    {
        int x;
        cin>>c[i]>>d[i]>>x;
        vec[x].pb(i);
    }
    getsum(1);
    dfs(1);
    int ans=0;
    for (int i=0;i<=n;i++)
        if (dp[1][i][1]<=k) ans=max(ans,i);
    for (int i=0;i<=n;i++)
        if (dp[1][i][0]<=k) ans=max(ans,i);
    cout<<ans;
}