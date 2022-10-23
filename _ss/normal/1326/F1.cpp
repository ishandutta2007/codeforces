#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
 
#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e6+10;
ll dp[N][25];
int n,a[25][25],mask[N][2],mm;
vector<int> vt[25],bit[N];
 
void read()
{
    cin>>n;
    string s;
    mm=(1<<n)-1;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        for (int j=1;j<=n;j++)
        {
            a[i][j]=(s[j-1]=='1');
            if (a[i][j]) mask[i][1]|=1<<(j-1);
        }
        mask[i][0]=mm^mask[i][1];
    }
}
 
void dfs(int id)
{
    if (id==n)
    {
        ll res=0;
        for (int x : vt[id])
            for (int i=1;i<=n;i++) res+=dp[x][i];
        cout<<res<<" ";
        return;
    }
    for (int v=0;v<=1;v++)
    {
        for (int x : vt[id])
            for (int i=1;i<=n;i++)
                if (dp[x][i])
                    for (int j : bit[(mm^x) & mask[i][v]]) dp[x^(1<<(j-1))][j]+=dp[x][i];
        dfs(id+1);
        for (int x : vt[id+1])
            for (int i=1;i<=n;i++) dp[x][i]=0;
    }
}
 
void pt(int x)
{
    int d=1,tmp=x;
    while (x)
    {
        if (x&1) bit[tmp].pb(d);
        d++;
        x>>=1;
    }
}
 
void process()
{
    for (int i=0;i<(1<<n);i++) vt[__builtin_popcount(i)].pb(i),pt(i);
    for (int i=1;i<=n;i++) dp[(1<<(i-1))][i]=1;
    dfs(1);
}
 
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}