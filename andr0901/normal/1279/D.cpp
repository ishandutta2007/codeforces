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

const int MOD = 998244353;

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

int bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    return (1LL * bin_pow(a, p / 2) * bin_pow(a, p / 2)) % MOD;
}

int rev(int x) {
    return bin_pow(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    //cout << mul(1, rev(4)) << "\n";
    int n;
    cin >> n;
    vector <vector <int>> a(n);
    vector <int> b(1e6 + 1);
    forn (i, 0, n) {
        int k;
        cin >> k;
        a[i].resize(k);
        forn (j, 0, k) {
            cin >> a[i][j];
            b[a[i][j]] = add(b[a[i][j]], rev(mul(n, k)));
        }
    }
    int ans = 0;
    forn (i, 0, n) {
        int sum = 0;
        for (int j : a[i]) {
            //cout << j << " " << b[j] << "\n";
            sum = add(sum, b[j]);
        }
        ans = add(ans, mul(sum, rev(n)));
        //cout << ans << " ";
    }
    cout << ans;
    return 0;
}