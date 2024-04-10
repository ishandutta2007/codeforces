#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int nxt() {
    int x;
    cin >> x;
    return x;
}

int MOD;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n = nxt();
    MOD = nxt();
    int k = nxt();
    map <int, int> a;
    forn (i, 0, n) {
        int x = nxt();
        a[sub(mul(mul(x, x), mul(x, x)), mul(k, x))]++;
    }
    ll ans = 0;
    for (const auto& i : a)
        ans += 1LL * i.sc * (i.sc - 1) / 2;
    cout << ans;
    return 0;
}