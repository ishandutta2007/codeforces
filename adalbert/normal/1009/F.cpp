#include <bits/stdc++.h>
#define pb push_back
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> vec[1100000];

int ans[1100000],num[1100000],len[1100000];
int best[1100000];
unordered_map<int,int> tutu[1100000];

void add(int to, int num, int cnt)
{
    tutu[to][num]+=cnt;
    int p1=tutu[to][num];
    int p2=tutu[to][best[to]];

    if (p1>p2 || (p1==p2 && best[to]>num))
        best[to]=num;
}

void solve(int u, int pred, int ln)
{
    len[u]=ln;
    for (auto i:vec[u])
        if (i!=pred)
    {
        solve(i,u,ln+1);
        if (tutu[num[u]].size()<tutu[num[i]].size())
            swap(num[i],num[u]);
        for (auto j:tutu[num[i]])
        {
            add(num[u],j.fir,j.sec);
        }
    }
    add(num[u],len[u],1);


    ans[u]=best[num[u]];
}

signed main()
{
    int n;
    cin>>n;

    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        vec[x].pb(y);
        vec[y].pb(x);
    }

    for (int i=1;i<=n;i++)
        num[i]=i;
    solve(1,0,0);

    for (int i=1;i<=n;i++)
    {
        cout<<ans[i]-len[i]<<' ';
    }
}
/*
*/