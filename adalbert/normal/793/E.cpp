#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
int dp[500000];
bool bag(vector<int> vec, int u)
{
    for (int i=0;i<=u;i++)
        dp[i]=0;
    dp[0]=1;
    for (int i=0;i<vec.size();i++)
        for (int j=u;j>=0;j--)
        if (dp[j]) dp[j+vec[i]]=1;
    return(dp[u]);
}
int a,b,c,d,sum[500000];
vector<int> vec[500000];
bool is_a[500000], is_b[500000],is_c[5000000],is_d[5000000];
void dfs(int u, int pred)
{
    if (vec[u].empty()) sum[u]=1;
    for (int i=0;i<vec[u].size();i++)
        if (vec[u][i]!=pred)
        {
            dfs(vec[u][i],u);
            sum[u]+=sum[vec[u][i]];
            if (is_a[vec[u][i]]) is_a[u]=1;
            if (is_b[vec[u][i]]) is_b[u]=1;
            if (is_c[vec[u][i]]) is_c[u]=1;
            if (is_d[vec[u][i]]) is_d[u]=1;
        }
}
signed main()
{
    int n;
    cin >> n;
    cin >> a >> b >> c >> d;
    is_a[a]=1;
    is_b[b]=1;
    is_c[c]=1;
    is_d[d]=1;
    for (int i=1;i<n;i++)
    {
        int f;
        cin >> f;
        vec[f].pb(i+1);
    }
    dfs(1,0);
    /*for (int i=1;i<=n;i++)
        cout<<is_a[i]<<' '<<is_b[i]<<' '<<is_c[i]<<' '<<is_d[i]<<'\n';*/
    vector<int> can_c(0),can_a(0);
    for (int i=1;i<=n;i++)
    {
        if (is_a[i])
        {
            for (int j=0;j<vec[i].size();j++)
                if (!is_a[vec[i][j]] && !is_b[vec[i][j]])
                can_a.pb(sum[vec[i][j]]);
        }
        if (is_b[i] && i!=1)
        {
            for (int j=0;j<vec[i].size();j++)
                if (!is_a[vec[i][j]] && !is_b[vec[i][j]])
                can_a.pb(sum[vec[i][j]]);
        }
        if (is_c[i])
        {
            for (int j=0;j<vec[i].size();j++)
                if (!is_c[vec[i][j]] && !is_d[vec[i][j]])
                can_c.pb(sum[vec[i][j]]);
        }
        if (is_d[i] && i!=1)
        {
            for (int j=0;j<vec[i].size();j++)
                if (!is_c[vec[i][j]] && !is_d[vec[i][j]])
                can_c.pb(sum[vec[i][j]]);
        }
    }
    if (sum[1]%2==1)
    {
        cout<<"NO";
        return(0);
    }
    if (bag(can_a,sum[1]/2-1) && bag(can_c,sum[1]/2-1) ) cout<<"YES"; else cout<<"NO";

}