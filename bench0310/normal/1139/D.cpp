#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    vector<int> sieve(m+1,0);
    for(int i=1;i<=m;i++) sieve[i]=i;
    vector<int> pre[m+1];
    for(ll i=2;i<=m;i++)
    {
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=m;j+=i) if(sieve[j]==j) sieve[j]=i;
        pre[i].push_back(1);
        while(pre[i].back()*i<=m) pre[i].push_back(pre[i].back()*i);
    }
    ll inv=fpow(m,mod-2);
    vector<ll> e(m+1,0);
    auto solve=[](int n,vector<int> bad)->int
    {
        int res=0;
        int cnt=bad.size();
        for(int i=0;i<(1<<cnt);i++)
        {
            int l=1;
            bool x=0;
            for(int j=0;j<cnt;j++)
            {
                if(i&(1<<j))
                {
                    l=lcm(l,bad[j]);
                    x^=1;
                }
            }
            if(x==0) res+=(n/l);
            else res-=(n/l);
        }
        return res;
    };
    auto add=[](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[](ll a,ll b)->ll{return ((a-b)%mod+mod)%mod;};
    auto mul=[](ll a,ll b)->ll{return (a*b)%mod;};
    auto div=[](ll a,ll b)->ll{return (a*fpow(b,mod-2))%mod;};
    for(int o=2;o<=m;o++)
    {
        vector<array<int,2>> a;
        int t=o;
        while(t>1)
        {
            int d=sieve[t];
            a.push_back({d,0});
            while((t%d)==0)
            {
                t/=d;
                a.back()[1]++;
            }
        }
        int primes=a.size();
        vector<int> b(primes,0);
        ll p0=0;
        ll sum=0;
        function<void(int,int)> gen=[&](int idx,int now)
        {
            if(idx==primes)
            {
                vector<int> bad;
                int f=1;
                for(int i=0;i<primes;i++)
                {
                    f*=pre[a[i][0]][b[i]];
                    if(b[i]<a[i][1]) bad.push_back(a[i][0]);
                }
                if(now<o) sum=add(sum,mul(mul(solve(m/f,bad),inv),e[now]+1));
                else p0=mul(solve(m/f,bad),inv);
            }
            else
            {
                int z=1;
                for(int i=0;i<=a[idx][1];i++)
                {
                    b[idx]=i;
                    gen(idx+1,now*z);
                    z*=a[idx][0];
                }
            }
            e[o]=div(add(sum,p0),sub(1,p0));
        };
        gen(0,1);
    }
    ll res=0;
    for(int i=1;i<=m;i++) res=add(res,mul(mul(1,inv),e[i]+1));
    cout << res << "\n";
    return 0;
}