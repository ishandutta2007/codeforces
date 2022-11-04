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
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"
#define int ll

int minu=200000;
set<int> ans;

bool visit[500000],use[500000];
int gt[500000];
vector<int> vec[500000];

void bad()
{
    cout<<"No";
    exit(0);
}

void add_reb(vector<int> vec1, vector<int> vec2)
{
    for (int i=0;i<min(vec1.size(),vec2.size());i++)
        if (vec1[i]!=vec2[i])
        {
            vec[vec1[i]].pb(vec2[i]);
            return;
        }
    if (vec1.size()>vec2.size())
        bad();
}

vector<int> read()
{
    int n;
    cin>>n;
    vector<int> res;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        res.pb(a);
    }
    return(res);
}

void dfs(int u)
{
    use[u]=1;
    visit[u]=1;

    for (auto to:vec[u])
    {
        if (visit[to]) bad();
        if (!use[to]) dfs(to);

        if (gt[u]>gt[to])
        {
            if (ans.count(u)) bad(); else
            {
                gt[u]-=minu;
                if (gt[u]>gt[to])
                    bad();
                ans.insert(u);
            }
        }
    }
    visit[u]=0;
}

signed main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
        gt[i]=i;

    n--;
    vector<int> pred=read();
    while(n--)
    {
        vector<int> now=read();
        add_reb(pred,now);
        pred=now;
    }

    for (int i=1;i<=m;i++)
        if (!use[i])
            dfs(i);

    cout<<"Yes"<<'\n';
    cout<<ans.size()<<'\n';
    for (auto i:ans)
    {
        cout<<i<<' ';
    }
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