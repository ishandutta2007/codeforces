#include<bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
int const maxn = 1e6 + 5;
ll a[maxn];
ll b[maxn];
ll c[maxn];
ll pref[maxn];
ll inf = 1e18;

int check(int i) {
    if (i <= 1) return 0;
    for (int j = 2; j * j <= i; ++j) {
        if (i % j == 0) return 0;
    }
    return 1;
}

ll get(int i, int j, int w) {
    if (!(i <= w && w <= j)) return inf;
    ll ans = 0;
    for (int pos = i; pos <= j; ++pos) {
        ans += (ll)abs(pos - w) * (ll)c[pos];
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll sum = 0, ans = inf;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) b[i] = a[i];
    for (int i = 1; i <= n; ++i) sum += a[i];
    ll j = 2;
    vector < ll > T;
    while (j * j <= sum) {
        if (sum % j == 0) {
            T.push_back(j);
            while (sum % j == 0) sum /= j;
        }
        ++j;
    }
    if (sum != 1) T.push_back(sum);
    for (auto k : T) {
        for (int i = 1; i <= n; ++i) a[i] = b[i];
        int ptr = 1;
        ll f = 0;
        while (ptr <= n) {
            ll block = 0, s = ptr, go = -1;
            ll pos = 0;
            a[ptr] %= k;
            pref[ptr - 1] = 0;
            while (ptr <= n && block < k) {
                int add = min(a[ptr], k - block);
                block += add;
                if (block >= k / 2 && go == -1) go = ptr;
                pos += (ll)add * (ll)ptr;
                c[ptr] = add;
                pref[ptr] = pref[ptr - 1] + c[ptr];
                a[ptr] -= add;
                if (k != block && a[ptr] == 0) ptr++;
            }
            ll ss = inf, suff = 0, preff = 0;
            for (int pos = s; pos <= ptr; ++pos) {
                suff += c[pos] * pos;
            }
            for (int pos = s; pos <= ptr; ++pos) {
                suff -= c[pos] * pos;
                preff += c[pos] * pos;
                ss = min(ss, suff - (pref[ptr] - pref[pos]) * pos + pos * (pref[pos] - pref[s - 1]) - preff);
            }
            f += ss;
        }
        ans = min(ans, f);
    }
    if (ans == inf) cout << -1;
    else cout << ans << '\n';
    return 0;
}