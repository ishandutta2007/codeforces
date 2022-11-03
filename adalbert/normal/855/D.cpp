#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define time pdojegoritg
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")

int now_tree;
int len[200000],sum[200000],tree[200000],dp[200000][21];
vector<pair<int,int> > vec[200000];

void dfs(int u, int ln, int sm, int pred)
{
    len[u]=ln;
    sum[u]=sm;
    tree[u]=now_tree;
    dp[u][0]=pred;
    for (int i=1;i<=20;i++)
        dp[u][i]=dp[dp[u][i-1]][i-1];

    for (auto to:vec[u])
    {
        dfs(to.fir,ln+1,sm+to.sec,u);
    }
}

int lca(int a, int b)
{
    for (int i=20;i>=0;i--)
        if (len[a]-(1<<i)>=len[b]) a=dp[a][i];

    for (int i=20;i>=0;i--)
        if (len[b]-(1<<i)>=len[a]) b=dp[b][i];

    if (a==b) return(a);
    for (int i=20;i>=0;i--)
        if (dp[a][i]!=dp[b][i])
        {
            a=dp[a][i];
            b=dp[b][i];
        }

    return(dp[a][0]);
}

int parent[200000],type[200000];

signed main()
{
    int n;
    cin>>n;

    vector<int> roots;

    for (int i=1;i<=n;i++)
    {
        cin>>parent[i]>>type[i];
        if (parent[i]==-1)
        {
            roots.pb(i);
        } else
        {
            vec[parent[i]].pb({i,type[i]});
        }
    }

    for (auto i:roots)
    {
        now_tree++;
        dfs(i,0,0,0);
    }

    int q;
    cin>>q;
    while (q--)
    {
        int t,u,v;
        cin>>t>>u>>v;
        if (tree[u]!=tree[v] || u==v)
        {
            cout<<"NO"<<'\n';
            continue;
        }
        int a=lca(u,v);
        if (t==1)
        {
            if (a==u && sum[v]==sum[u])
                cout<<"YES"<<'\n'; else
                cout<<"NO"<<'\n';
        } else
        {
            if (sum[a]-sum[v]==len[a]-len[v] && sum[a]==sum[u] && v!=a)
                cout<<"YES"<<'\n'; else
                cout<<"NO"<<'\n';
        }
    }
}