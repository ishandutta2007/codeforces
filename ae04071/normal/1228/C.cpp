#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli MOD = 1e9+7;

int vis[40001];
vector<int> pa;

const lli INF = 1000000000000000001ll;
lli mul(lli a,lli b) {
    if(a>=INF || b>=INF || INF/a<b) return INF;
    else return min(INF, a*b);
}

lli power(lli a,lli p) {
    lli ret=1;
    while(p) {
        if(p&1) ret = ret*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ret;
}

int main() {
    lli x,n;
    scanf("%lld%lld",&x,&n);
    for(int i=2;i<=40000;i++) if(!vis[i]) {
        vis[i] = 1;
        for(int j=i*i;j<=40000;j+=i) vis[j] = 1;
        if(x%i==0) {
            while(x%i==0) x/=i;
            pa.push_back(i);
        }
    }
    if(x!=1) pa.push_back(x);

    lli ans=1;
    for(auto &it:pa) {
        lli val = it;
        while(val <= n) {
            ans = ans*power(it,n/val)%MOD;
            val = mul(val,it);
        }
    }
    printf("%lld\n",ans);

    return 0;
}