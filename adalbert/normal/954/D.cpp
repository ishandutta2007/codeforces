#include<bits/stdc++.h>
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
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;

vector<int> vec[300000];
int len1[100000], len2[100000];
bool can[2000][2000];

signed main()
{
    int n,m,s,f;
    cin>>n>>m>>s>>f;
    while (m--)
    {
        int a,b;
        cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
        can[a][b]=1;
        can[b][a]=1;
    }

    queue<int> q;
    q.push(s);
    for (int i=1;i<=n;i++)
    {
        len1[i]=1e9;
        len2[i]=1e9;
    }
    len1[s]=0;
    len2[f]=0;

    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (auto to:vec[u])
            if (len1[to]==1e9)
        {
            q.push(to);
            len1[to]=len1[u]+1;
        }
    }

    q.push(f);

    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (auto to:vec[u])
            if (len2[to]==1e9)
        {
            q.push(to);
            len2[to]=len2[u]+1;
        }
    }

    int res=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        if (!can[i][j] && len1[i]+len2[j]+1>=len1[f] && len2[i]+len1[j]+1>=len1[f])
        res++;
    cout<<res;
}
/*

*/