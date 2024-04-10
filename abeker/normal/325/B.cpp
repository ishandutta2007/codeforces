#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll N;

void load() {
    scanf("%I64d", &N);    
}

ll calc(ll x, ll k) {
    ll y = x + (1ll << k + 1) - 3;
    ll num = x * y;
    if (num / x != y) return N + 1;
    return num; 
}   

ll bs(ll k) {
    ll lo = 1, hi = N;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (calc(mid, k) >= N) hi = mid;
        else lo = mid + 1;
    }
    if (calc(lo, k) != N) return 0;
    return lo;
}

void solve() {
    N *= 2;
    vector <ll> sol;
    for (ll k = 0; k < 60; k++) {
        ll x = bs(k);
        if (x & 1ll) sol.push_back(x * (1ll << k));
    }
    sort(sol.begin(), sol.end());
    for (int i = 0; i < sol.size(); i++) 
        printf("%I64d\n", sol[i]);
    if (sol.empty()) puts("-1");
}

int main() {
    load();
    solve();
    return 0;
}