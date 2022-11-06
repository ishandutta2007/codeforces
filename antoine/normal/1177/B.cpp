#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll randMask() {
    ll x = uniform_int_distribution<int>(0, int((1LL << 31) - 1))(rng);
    ll y = uniform_int_distribution<int>(0, int((1LL << 31) - 1))(rng);
    return x << 31 | y;
}

int popCnt(ll mask) {
    int cnt = 0;
    while (mask) {
        cnt++;
        mask &= mask - 1;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ll k;
    cin >> k;

    int d = 1;
    ll curr = 9;
    ll sum = 9;
    ll last = 0;

    while (k > sum) {
        last = sum;
        curr *= 10;
        sum += curr * ++d;
    }

    k -= last + 1;
    const int pos = d - 1 - k % d;
    k /= d;

    for (int i = 0; i < pos; ++i)
        k /= 10;

    int ans = k % 10 + (pos == d - 1);
    cout << ans;
    return 0;
}