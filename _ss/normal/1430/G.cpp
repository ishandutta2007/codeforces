#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=(1<<20),inf=2e9;
int dp[20][N],adj1[N],val[N],n,adj2[N],ca[N],trace[20][N];
vi nex[N];

void read()
{
    int m;
    cin>>n>>m;
    for (int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        val[u]+=w;
        val[v]-=w;
        adj1[u]|=(1<<(v-1));
        adj2[v]|=(1<<(u-1));
    }
}

void dfs(int id,vi &vt,int mask,vi &content)
{
    if (id==(int)vt.size())
    {
        content.eb(mask);
        return;
    }
    dfs(id+1,vt,mask,content);
    dfs(id+1,vt,mask | (1<<(vt[id]-1)),content);
}

void gen(int adj[],int typ)
{
    for (int mask=0;mask<(1<<n);mask++)
    {
        int cnmask=0;
        vi vt;
        for (int j=1;j<=n;j++)
            if ((((mask>>(j-1))&1)==0) && ((adj[j] & mask) == adj[j]))
            {
                if (val[j]*typ>=0) cnmask^=(1<<(j-1));
                else vt.eb(j);
            }
        dfs(0,vt,cnmask,nex[mask]);
    }
}

int a[N];

void process1()
{
    gen(adj1,1);
    for (int i=0;i<=n;i++)
        for (int mask=0;mask<(1<<n);mask++) dp[i][mask]=inf;
    dp[0][0]=0;
    for (int i=0;i<n;i++)
        for (int mask=0;mask<(1<<n);mask++)
            for (int ad : nex[mask])
            {
                int dd=dp[i][mask]+ca[ad]*(i+1);
                if (dd<dp[i+1][mask^ad])
                {
                    dp[i+1][mask^ad]=dd;
                    trace[i+1][mask^ad]=mask;
                }
            }
    int mask=(1<<n)-1;
    for (int i=n;i;i--)
    {
        int nmask=trace[i][mask];
        int ad=nmask^mask;
        for (int j=1;j<=n;j++)
            if (((ad)>>(j-1))&1) a[j]=i;
        mask=nmask;
    }
}

void process2()
{
    gen(adj2,-1);
    for (int i=1;i<=n+1;i++)
        for (int mask=0;mask<(1<<n);mask++) dp[i][mask]=inf;
    dp[n+1][0]=0;
    for (int i=n+1;i>1;i--)
        for (int mask=0;mask<(1<<n);mask++)
            for (int ad : nex[mask])
            {
                int dd=dp[i][mask]+ca[ad]*(i-1);
                if (dd<dp[i-1][mask^ad])
                {
                    dp[i-1][mask^ad]=dd;
                    trace[i-1][mask^ad]=mask;
                }
            }
    int mask=(1<<n)-1;
    for (int i=1;i<=n;i++)
    {
        int nmask=trace[i][mask];
        int ad=nmask^mask;
        for (int j=1;j<=n;j++)
            if (((ad)>>(j-1))&1) a[j]=i;
        mask=nmask;
    }
}

void process()
{
    for (int mask=0;mask<(1<<n);mask++)
        for (int i=1;i<=n;i++)
            if ((mask>>(i-1))&1) ca[mask]+=val[i];
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (val[i]>=0) cnt++;
    if (2*cnt>=n) process1();
    else process2();
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    /*cout<<"\n";
    for (int mask=0;mask<(1<<n);mask++)
    {
        cout<<mask<<"\n";
        for (int ad : nex[mask]) cout<<ad<<" ";
        cout<<"\n";
    }*/
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