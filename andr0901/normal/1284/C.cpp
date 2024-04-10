#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
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

int mul(int x, int y, int z, int t) {
    return mul(mul(x, y), mul(z, t));
}

vector <int> f;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> MOD;
    f.resize(n + 1, 1);
    forn (i, 1, n + 1)
        f[i] = mul(f[i - 1], i);
    int ans = 0;
    forn (i, 1, n + 1) {
        ans = add(ans, mul(n - i + 1, n - i + 1, f[i], f[n - i]));
        //cout << ans << " ";
    }
    cout << ans;
    return 0;
}