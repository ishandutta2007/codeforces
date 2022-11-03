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
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
const int md=1e9+7;

int cnt[arr];

int all[arr];

vector<int> dil[arr];
vector<int> vec[arr];

vector<int> parse(int u)
{
    vector<int> res;
    for (int i=1;i*i<=u;i++)
        if (u%i==0)
    {
        res.pb(i);
        if (u/i!=i)
            res.pb(u/i);
    }
    return(res);
}

int ans[arr];
int a[arr],cost[arr];

int nsd(int a, int b)
{
    while (a!=0 && b!=0)
        if (a>b) a%=b; else b%=a;
    return(a+b);
}

void dfs(int u, int pred, int len)
{
    cost[u]=nsd(cost[pred],a[u]);
    int mx=0;
    for (int i=0;i<dil[u].size();i++)
    {
        cnt[dil[u][i]]++;

        if (cnt[dil[u][i]]>=len-1)
            ans[u]=max(ans[u],dil[u][i]);
    }

    ans[u]=max(ans[u],cost[pred]);

    for (int i=0;i<vec[u].size();i++)
        if (vec[u][i]!=pred)
        dfs(vec[u][i],u,len+1);

    for (int i=0;i<dil[u].size();i++)
    {
        cnt[dil[u][i]]--;
    }
}



signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        dil[i]=parse(a[i]);
    }
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].pb(v);
        vec[v].pb(u);
    }

    dfs(1,0,1);

    for (int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
}