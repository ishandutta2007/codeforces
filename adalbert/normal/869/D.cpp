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
#define files(name) freopen("input.txt","r",stdin); freopen ("output.txt","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define int ll
#define endl "\n"
int md=1e9+7;
int n,result;
set<int> choosen;
map<int,int> mp;
int cost[10000],back_[10000],l[10],r[10],use[10000];
vector<pair<int,int> > vec[10000];
int mn;
void add(int u)
{
    while (u!=0)
    {
        choosen.insert(u);
        u/=2;
    }
}

int get(int u)
{
    int left=u;
    int right=u;
    int res=0;
    while (left<=n)
    {
        res+=(min(n,right)-left+1);
        left=left*2;
        right=right*2+1;
        res%=md;
    }
    return(res);
}

bool ch;
int m;
void dfs(int u)
{

    result+=cost[u]%md*mn*ch%md;
    result%=md;
    use[u]=1;
    for (auto i:vec[u])
        if (!use[i.fir])
        {
            bool now=ch;
            ch|=i.sec;
            dfs(i.fir);
            ch=now;
        }

    use[u]=0;
}

signed main()
{

    cin>>n>>m;
    result=n*n;
    if (m==0)
    {
        cout<<n*n%md;
        return(0);
    }

    for (int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i];
        add(l[i]);
        add(r[i]);
    }


    vector<pair<int,int> > other;

    for (auto u:choosen)
    {
        if (!choosen.count(u*2) && u*2<=n)
        {
            other.pb({u*2,get(u*2)});
        }
        if (!choosen.count(u*2+1) && u*2+1<=n)
        {
            other.pb({u*2+1,get(u*2+1)});
            //cout<<u*2+1<<' '<<get(u*2+1)<<'\n';
        }
        other.pb({u,1});
    }


    int cnt=0;
    for (auto i:other)
    {
        int u=i.fir;
        mp[u]=++cnt;
    }

    for (auto i:other)
    {
        int u=i.fir;
        cost[mp[u]]=i.sec;
        back_[mp[u]]=u;
        if (mp.count(u*2))
        {
            vec[mp[u]].pb({mp[u*2],0});
            vec[mp[u*2]].pb({mp[u],0});
        }

        if (mp.count(u*2+1))
        {
            vec[mp[u]].pb({mp[u*2+1],0});
            vec[mp[u*2+1]].pb({mp[u],0});
        }
    }

    for (int i=1;i<=m;i++)
    {
        vec[mp[l[i]]].pb({mp[r[i]],1});
        vec[mp[r[i]]].pb({mp[l[i]],1});
    }

    //cout<<result<<'\n';
    for (int i=1;i<=cnt;i++)
    {
        mn=cost[i];
        dfs(i);
    }
    cout<<result;
}
/*
15 3
1 2
2 3
1 7
*/