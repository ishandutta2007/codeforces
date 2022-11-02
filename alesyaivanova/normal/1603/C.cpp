#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
int a[maxn];
int d[maxn];
int n;
int mod = 998244353;

int add(int x, int y) {
    if (x + y < mod) {
        return x + y;
    }
    return x + y - mod;
}

int sub(int x, int y) {
    if (x - y >= 0) {
        return x - y;
    }
    return x - y + mod;
}

int mul(int a, int b) {
    return (a * 1ll * b) % mod;
}

int up(int x, int y) {
    return (x + y - 1) / y;
}

int down(int x, int y) {
    return x / y;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int e = i - 1; e >= 0 && up(a[e], d[e]) > down(a[e + 1], d[e + 1]); e--) {
            int x = down(a[e + 1], d[e + 1]);
            sum = sub(sum, mul(d[e] - 1, e + 1));
            d[e] = up(a[e], x);
            sum = add(sum, mul(d[e] - 1, e + 1));;
        }
        ans = add(ans, sum);
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}