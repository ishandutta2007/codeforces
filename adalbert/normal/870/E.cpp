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
#define time pdojegoritg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"
#define int ll
#define sec second

const int md=1e9+7;

set<int> setikx,setiky;
map<int,vector<pair<int,int> > > mpx,mpy;

int x[200000],y[200000],use[200000],visit[200000];
bool ch;
vector<int> reb[200000];

void dfs(int u, int pred)
{
    setikx.insert(x[u]);
    setiky.insert(y[u]);
    use[u]=1;
    visit[u]=1;
    for (auto to: reb[u])
    if (to!=pred)
    {
        //cout<<to<<"!!!!!!!!"<<'\n';
        if (visit[to]) ch=1; else
        if (!use[to])
        dfs(to,u);
    }
    visit[u]=0;
}

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        mpx[x[i]].pb({y[i],i});
        mpy[y[i]].pb({x[i],i});
    }

    for (auto i:mpx)
    {
        vector<pair<int,int> > vec=i.second;
        sort(vec.begin(),vec.end());
        for (int i=1;i<vec.size();i++)
        {
            reb[vec[i-1].sec].pb(vec[i].sec);
            reb[vec[i].sec].pb(vec[i-1].sec);
        }

    }

    for (auto i:mpy)
    {
        vector<pair<int,int> > vec=i.sec;
        sort(vec.begin(),vec.end());
        for (int i=1;i<vec.size();i++)
        {
            reb[vec[i-1].sec].pb(vec[i].sec);
            reb[vec[i].sec].pb(vec[i-1].sec);
        }

    }

    int ans=1;
    for (int i=1;i<=n;i++)
    if (!use[i])
    {
        setikx.clear();
        setiky.clear();
        ch=0;
        dfs(i,0);

        int step=setikx.size()+setiky.size();
        int now=1;
        while (step--)
        {
            now*=2;
            now%=md;
        }
        if (!ch)
            now--;
        ans*=now;
        ans%=md;
    }
    cout<<ans;
}
/*
1
2 1
2 10 100
2 100 10
2 1 10
2 1 5
1 1 2 2
*/