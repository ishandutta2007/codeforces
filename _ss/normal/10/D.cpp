#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=501;
int n,m,a[maxn],b[maxn],f[maxn],tv[maxn];

void read()
{
    cin>>m;
    for (int i=1;i<=m;i++) scanf("%d",&a[i]);
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
}

void dp()
{
    for (int i=1;i<=m;i++)
    {
        int val=0,t=0;
        for (int j=1;j<=n;j++)
            if (b[j]<a[i] && f[j]>val)
            {
                val=f[j];
                t=j;
            }
            else if (a[i]==b[j] && val+1>f[j])
            {
                f[j]=val+1;
                tv[j]=t;
            }
    }
}

void process()
{
    int ans=0,t=0;
    for (int j=1;j<=n;j++) f[j]=tv[j]=0;
    dp();
    for (int j=1;j<=n;j++)
    if (f[j]>ans)
    {
        ans=f[j];
        t=j;
    }
    printf("%d\n",ans);
    vector<int> c;
    while (t!=0)
    {
        c.pb(b[t]);
        t=tv[t];
    }
    for (int i=c.size()-1;i+1;i--) printf("%d ",c[i]);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}