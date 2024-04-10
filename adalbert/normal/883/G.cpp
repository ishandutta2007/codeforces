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
typedef long double ld;
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
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"


int n,m,u,ans;

int type[400000],start[400000],finish[400000],t[400000],use[400000];
vector<pair<int,int> > vec[400000];

void solve1(int u)
{
    ans++;
    use[u]=1;
    for (auto to:vec[u])
    {
        int in=to.sec;
        int v=to.fir;
        if (!use[v])
        {
            if (u!=start[in])
                type[in]=1;
            solve1(v);
        }
    }
}
void solve2(int u)
{
    ans++;
    use[u]=1;
    for (auto to:vec[u])
    {
        int in=to.sec;
        int v=to.fir;
        if (!use[v])
        {
            if (t[in]==1)
                solve2(v); else
            {
                if (u==start[in])
                type[in]=1;
            }

        }
    }
}

signed main()
{
    cin>>n>>m>>u;
    for (int i=1;i<=m;i++)
    {
        cin>>t[i]>>start[i]>>finish[i];
        if (t[i]==1)
        {
            vec[start[i]].pb({finish[i],i});
        } else
        {
            vec[start[i]].pb({finish[i],i});
            vec[finish[i]].pb({start[i],i});
        }
    }

    solve1(u);
    cout<<ans<<'\n';
    for (int i=1;i<=m;i++)
        if (t[i]==2 && type[i])
        cout<<'-'; else
        if (t[i]==2)
        cout<<'+';
    cout<<'\n';

    for (int i=1;i<=n;i++)
        use[i]=0;
    for (int i=1;i<=m;i++)
        type[i]=0;
    ans=0;

    solve2(u);
    cout<<ans<<'\n';
    for (int i=1;i<=m;i++)
        if (t[i]==2 && type[i])
        cout<<'-'; else
        if (t[i]==2)
        cout<<'+';
    cout<<'\n';
}