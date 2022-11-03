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


bool ok[3010][3010];
short int nxt[3001][3001][12];

vector<int> vec[3001];

void dfs(int u, int pr)
{
    ok[pr][u]=1;
    for (auto i:vec[u])
    {
        if (!ok[pr][i])
            dfs(i,pr);
    }
}

int get(int u, int f, int len)
{
    for (int i=11;i>=0;i--)
        if ((1<<i)<=len)
        {
            len-=(1<<i);
            u=nxt[u][f][i];
            if (len==0)
                return(u);
            if (u==-1)
                return(-1);
        }
    return(u);
}

signed main()
{
    fast;
    int n,m,q;
    cin>>n>>m>>q;

    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        vec[x].pb(y);
    }

    for (int i=1;i<=n;i++)
    {
        dfs(i,i);
    }

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int l=0;l<vec[i].size();l++)
                if (i==j)
                nxt[i][j][0]=-1; else
                {
                    if (nxt[i][j][0]==0 && ok[vec[i][l]][j])
                        nxt[i][j][0]=vec[i][l];
                    if (ok[vec[i][l]][j])
                        nxt[i][j][0]=min((short int)(vec[i][l]),nxt[i][j][0]);
                }

    for (int i=1;i<=n;i++)
        nxt[i][i][0]=-1;

    for (int step=1;step<=11;step++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                if (nxt[i][j][step-1]==-1)
                    nxt[i][j][step]=-1; else
                    {
                        nxt[i][j][step]=nxt[nxt[i][j][step-1]][j][step-1];
                    }
            }

    while (q--)
    {
        int s,t,k;
        cin>>s>>t>>k;
        if (get(s,t,n)!=-1)
            cout<<-1<<'\n'; else
            {
                k--;
                //if (k==0)
                //    cout<<s<<'\n'; else
                cout<<get(s,t,k)<<'\n';
            }
    }
}
/*
7 7 1
1 2
2 3
1 3
3 4
4 5
5 3
4 6
1 4 2
*/