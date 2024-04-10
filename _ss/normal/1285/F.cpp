#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#pragma GCC target("avx2")

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5,mod=1e9+7,inf=1e18;

int mark[N+10],lp[N+10];
vector<int> bit[N+10];

void read()
{
    int n,x;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&x),mark[x]=1;
}

vector<int> ptnt(int x)
{
    vector<int> res;
    while (lp[x])
    {
        int tmp=lp[x];
        res.pb(tmp);
        while (lp[x]==tmp) x/=lp[x];
    }
    return res;
}

int getv(vector<int> vt)
{
    for (int j=N/32-1;j>=0;j--)
    {
        int t=bit[0][j];
        for (int x : vt) t&=bit[x][j];
        if (t)
        {
            for (int i=31;i>=0;i--)
                if ((t>>i)&1) return j*32+i+1;
        }
    }
    return 1;
}

void process()
{
    for (int i=1;i<=N;i++)
        for (int j=i;j<=N;j+=i)
            if (mark[j])
            {
                mark[i]=1;
                break;
            }
    for (int i=2;i<=N;i++)
        if (!lp[i])
        {
            bit[i].resize(N/32,-1);
            for (int j=i;j<=N;j+=i)
            {
                if (!lp[j]) lp[j]=i;
                bit[i][(j-1)/32]^=(1<<((j-1)%32));
            }
        }
    bit[0].resize(N/32,0);
    for (int i=1;i<=N;i++)
        if (mark[i]) bit[0][(i-1)/32]^=(1<<((i-1)%32));
    ll ans=1;
    for (int i=2;i<=N;i++)
        if (mark[i]) ans=max(ans,(ll)i*getv(ptnt(i)));
    cout<<ans;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}