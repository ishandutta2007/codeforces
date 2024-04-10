#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=5e2+10,mod=998244353;
ll a[maxn],n,m,s[maxn][maxn],f[maxn][maxn],mark[maxn];

void read()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++) scanf("%I64d",&a[i]),mark[a[i]]=i;
}

void add(ll &t1,ll t2)
{
    t1+=t2;
    if (t1>=mod) t1-=mod;
}

ll multi(ll t1,ll t2)
{
    return (t1*t2)%mod;
}

void process()
{
    for (int i=1;i<=m;i++)
    {
        s[i][i]=a[i];
        for (int j=i+1;j<=m;j++) s[i][j]=min(s[i][j-1],a[j]);
        for (int j=i;j<=m;j++) s[i][j]=mark[s[i][j]];
    }
    for (int i=n;i;i--)
    {
        int vt=mark[i];
        int l=vt-1,r=vt+1;
        f[vt][vt]=1;
        while (a[l]>a[vt])
        {
            int t=s[l][vt-1];
            add(f[vt][l],multi(f[t][l],f[t][vt-1]));
            add(f[vt][l],multi(f[t][l],f[t][vt-1]));
            for (int j=vt-1;j>l;j--)
            {
                int t1=s[j][vt-1],t2=s[l][j-1];
                add(f[vt][l],multi(multi(f[t1][j],f[t1][vt-1]),multi(f[t2][l],f[t2][j-1])));
            }
            l--;
        }
        while (a[r]>a[vt])
        {
            int t=s[vt+1][r];
            add(f[vt][r],multi(f[t][vt+1],f[t][r]));
            add(f[vt][r],multi(f[t][vt+1],f[t][r]));
            for (int j=vt+1;j<r;j++)
            {
                int t1=s[vt+1][j],t2=s[j+1][r];
                add(f[vt][r],multi(multi(f[t1][vt+1],f[t1][j]),multi(f[t2][j+1],f[t2][r])));
            }
            r++;
        }
    }
    cout<<multi(f[mark[1]][1],f[mark[1]][m]);
}

int main()
{
    read();
    process();
    return 0;
}