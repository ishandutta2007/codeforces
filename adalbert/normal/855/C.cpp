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

ll n,m,k,x;
const ll md=1e9+7;
vector<int> vec[200000];
ll dp[200000][12][3];
ll sum[200000][12];
void solve0(int u, int cnt, int pred)
{

    for (int i=0;i<=cnt;i++)
        for (int j=0;j<=vec[u].size();j++)
            sum[j][i]=0;
    sum[0][0]=1;

    for (int i=0;i<vec[u].size();i++)
        if (vec[u][i]==pred)
        {
            for (int j=0;j<=cnt;j++)
                sum[i+1][j]=sum[i][j];
        } else
        {
            for (int pred=0;pred<=cnt;pred++)
                for (int now=0;now+pred<=cnt;now++)
                {
                    sum[i+1][pred+now]+=sum[i][pred]*dp[vec[u][i]][now][1]%md;
                    sum[i+1][pred+now]%=md;
                    sum[i+1][pred+now]+=sum[i][pred]*dp[vec[u][i]][now][0]%md;
                    sum[i+1][pred+now]%=md;
                    sum[i+1][pred+now]+=sum[i][pred]*dp[vec[u][i]][now][2]%md;
                    sum[i+1][pred+now]%=md;
                }
        }
}

void solve2(int u, int cnt, int pred)
{
    for (int i=0;i<=cnt;i++)
        for (int j=0;j<=vec[u].size();j++)
            sum[j][i]=0;
    sum[0][0]=1;

    for (int i=0;i<vec[u].size();i++)
        if (vec[u][i]==pred)
        {
            for (int j=0;j<=cnt;j++)
                sum[i+1][j]=sum[i][j];
        } else
        {
            for (int pred=0;pred<=cnt;pred++)
                for (int now=0;now+pred<=cnt;now++)
                {
                    sum[i+1][pred+now]+=sum[i][pred]*dp[vec[u][i]][now][0]%md;
                    sum[i+1][pred+now]%=md;
                    sum[i+1][pred+now]+=sum[i][pred]*dp[vec[u][i]][now][2]%md;
                    sum[i+1][pred+now]%=md;
                }
        }
}

void solve1(int u, int cnt, int pred)
{

    if (cnt==0) return;
    for (int i=0;i<=cnt;i++)
        for (int j=0;j<=vec[u].size();j++)
            sum[j][i]=0;
    sum[0][0]=1;

    for (int i=0;i<vec[u].size();i++)
        if (vec[u][i]==pred)
        {
            for (int j=0;j<=cnt;j++)
                sum[i+1][j]=sum[i][j];
        } else
        {
            for (int pred=0;pred<=cnt;pred++)
                for (int now=0;now+pred<=cnt;now++)
                {
                    sum[i+1][pred+now]+=sum[i][pred]*dp[vec[u][i]][now][0]%md;
                    sum[i+1][pred+now]%=md;
                }
        }
}

void solve(int u, int pred)
{
    for (int i=0;i<vec[u].size();i++)
    if (vec[u][i]!=pred)
        solve(vec[u][i],u);




        solve0(u,x,pred);

        for (int i=0;i<=x;i++)
        {
            dp[u][i][0]=sum[vec[u].size()][i]*(k-1)%md;
        }


        solve1(u,x,pred);

        for (int i=1;i<=x;i++)
            dp[u][i][1]=sum[vec[u].size()][i-1];


        solve2(u,x,pred);

        for (int i=0;i<=x;i++)
            dp[u][i][2]=sum[vec[u].size()][i]*(m-k)%md;

}

signed main()
{
fast;
    cin>>n>>m;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].pb(v);
        vec[v].pb(u);
    }

    cin>>k>>x;

    solve(1,0);

    int ans=0;
    for (int i=0;i<=x;i++)
    {
        ans+=dp[1][i][0];
        ans%=md;
        ans+=dp[1][i][1];
        ans%=md;
        ans+=dp[1][i][2];
        ans%=md;
    }
    cout<<ans;
}