#include <bits/stdc++.h>

using namespace std;
long long f, T, t0;
long long a1, a2, t1, t2, p1, p2;
const long long inf = 5e18;

long long get(long long T, long long p, long long a, long long t, long long need) {
    if(need * t0 <= T) return 0;
    if(t0 <= t) {
        return inf;
    }
    //(need-x*a) * t0 + x * a * t <= T
    //need * t0 - x * a * t0 + x * a * t <= T
    //need * t0 - T <= x * a * (t0-t)
    long long val1 = need * t0 - T;
    long long val2 = a * (t0 - t);
    long long X = (val1+val2 - 1)/val2;
    long long x2 = (need + a-1)/a;
    long long ans = inf;
    if(x2 * a * t <= T) {
        ans = min(ans, x2 * p);
    }
    for(int it = -1; it <= 1; it++) {
        long long x = max(X + it, 0ll);
        if (min(x * a, need) * t + max(need - x * a, 0ll) * t0 <= T) {
            ans = min(ans, x * p);
        }
    }

    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> f >> T >> t0;
    cin >> a1 >> t1 >> p1;
    cin >> a2 >> t2 >> p2;
    if (1LL * f * t0 <= T) {
        puts("0");
        return 0;
    }

    long long ans = inf;
    for(int i = 0; i <= f; i++) {
        long long down = min(a1 * i, f);
        long long curPrice = p1 * i;
        long long ti = T - down * t1;
        if(ti < 0) break;
        curPrice += get(ti, p2, a2, t2, f-down);
        ans=min(curPrice, ans);
    }
    for(int i = 0; i <= f; i++) {
        long long down = min(a2 * i, f);
        long long curPrice = p2 * i;
        long long ti = T - down * t2;
        if(ti < 0) break;
        curPrice += get(ti, p1, a1, t1, f-down);
        ans=min(curPrice, ans);
    }
    if(ans == inf) ans = -1;
    cout << ans << "\n";
}