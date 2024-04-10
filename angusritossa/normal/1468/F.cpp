#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a%b) : a;
}

const long long MAXN = 1e5+5;

map<pair<long long,long long>,long long> counts;

void solve() {
    long long ans = 0;
    counts.clear();
    long long n;
    scanf("%lld",&n);
    for (long long i=0;i<n;i++) {
        long long x,y,u,v;
        scanf("%lld %lld %lld %lld",&x,&y,&u,&v);
        long long xd = u-x;
        long long yd = v-y;
        if (xd == 0) {
            if (yd > 0) {
                yd = 1;
            } else {
                yd = -1;
            }
        } else if (yd == 0) {
            if (xd > 0) {
                xd = 1;
            } else {
                xd = -1;
            }
        } else {
            long long gecd = gcd(abs(xd),abs(yd));
            xd /= gecd;
            yd /= gecd;
        }
        ans += counts[make_pair(-xd,-yd)];
        counts[make_pair(xd,yd)]++;
    }
    printf("%lld\n",ans);
}

int main() {
    long long t;
    scanf("%lld",&t);
    for (long long i=0;i<t;i++) {
        solve();
    }
}