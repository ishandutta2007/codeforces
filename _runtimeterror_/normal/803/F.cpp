#include<iostream>
#include<vector>
using namespace std;

const int N = 100005;
const int mod = 1000000007;
long long pow_2[N],a[N],f[N],g[N];
vector<int> pr[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);

    pow_2[0] = 1;
    for(int i=1;i<=n;++i)
        pow_2[i] = pow_2[i-1] * 2 % mod;

    for(int i=2;i<100000;++i)
    {
        if(!pr[i].empty())
            continue;
        for(int j=i;j<=100000;j+=i)
            pr[j].push_back(i);
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<(1<<(int)pr[a[i]].size());++j)
        {
            int u = 1;
            for(int k=0;k<pr[a[i]].size();++k)
                if(j&(1<<k))
                    u *= pr[a[i]][k];
            ++f[u];
            g[u] = __builtin_popcount(j)&1?-1:1;
        }
    }
    long long ans = pow_2[n]-1;
    for(int i=2;i<=100000;++i)
    {
        if(f[i])
            ans += g[i]*(pow_2[f[i]]-1);
        ans = (ans + mod)%mod;
    }
    printf("%lld\n",ans);
}