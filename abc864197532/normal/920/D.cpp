#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define test(x) cout << #x << ' ' << x << endl
#define printv(x) { \
    for (auto a : x) cout << a << ' '; \
    cout << endl; \
}
#define pii pair<int, int>
#define pll pair<lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int N = 100, abc = 864197532, K = 700, mod = 1e9 + 7;

bool dp[5001][5000];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, v;
    cin >> n >> k >> v;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    lli sum = accumulate(all(a), 0ll);
    if (sum < v) {
        cout << "NO\n";
        return 0;
    }
    if (v % k == 0) {
        cout << "YES\n";
        for (int i = 1; i < n; ++i) {
            cout << abc << ' ' << i + 1 << " 1" << endl;
        }
        if (v) cout << v / k << ' ' << "1 2" << endl;
        return 0;
    }
    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) if (dp[i][j]) {
            dp[i + 1][(j + a[i]) % k] = true;
            dp[i + 1][j] = true;
        }
    }
    if (!dp[n][v % k]) {
        cout << "NO\n";
        return 0;
    }
    vector <bool> choose(n, false);
    int ni = n, nj = v % k;
    while (ni > 0) {
        if (dp[ni - 1][(nj - a[ni - 1] % k + k) % k]) {
            ni--;
            choose[ni] = true;
            nj = (nj - a[ni] % k + k) % k;
        } else {
            ni--;
        }
    }
    int x = -1, y = -1;
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (choose[i]) {
            if (x == -1) x = i;
            else cout << abc << ' ' << i + 1 << ' ' << x + 1 << endl, a[x] += a[i];
        } else {
            if (y == -1) y = i;
            else cout << abc << ' ' << i + 1 << ' ' << y + 1 << endl, a[y] += a[i];
        }
    }
    if (y == -1) {
        y = x ? 0 : 1;
    }
    if (a[x] > v) {
        cout << (a[x] - v) / k << ' ' << x + 1 << ' ' << y + 1 << endl;
    } else if (a[x] < v) {
        cout << (v - a[x]) / k << ' ' << y + 1 << ' ' << x + 1 << endl;
    }
}