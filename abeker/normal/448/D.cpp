#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, M, K;

void load() {
    cin >> N >> M >> K;    
}

ll f(ll val) {
    ll ret = 0;
    for (ll i = 1; i <= N; i++)  
        ret += min(val / i, M);
    return ret;
}

ll solve() {
    ll lo = 1, hi = N * M, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        //cout << lo << ' ' << hi << ' ' << mid << endl;
        if (f(mid) < K) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main() {
    load();
    cout << solve() << endl;
    //cout << f(2) << endl;
    return 0;
}