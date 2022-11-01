#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=998244353;

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
    int n;
    cin >> n;
    ll inv=fpow(100,mod-2);
    ll one=0;
    ll m=1;
    for(int i=1;i<=n;i++)
    {
        ll p;
        cin >> p;
        p=(p*inv)%mod;
        one=(one+m)%mod;
        m=(m*p)%mod;
    }
    cout << (one*fpow(m,mod-2))%mod << "\n";
    return 0;
}