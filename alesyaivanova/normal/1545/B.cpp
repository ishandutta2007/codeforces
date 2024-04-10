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
int mod = 998244353;
int a[maxn];
int n;
int f[maxn];
int rf[maxn];

int mult(int x, int y) {
    return (x * 1ll * y) % mod;
}

int binpow(int x, int p) {
    int y = x;
    int ans = 1;
    while (p) {
        if (p % 2 == 1) {
            ans = mult(ans, y);
        }
        y = mult(y, y);
        p /= 2;
    }
    return ans;
}

int divv(int x, int y) {
    return mult(x, binpow(y, mod - 2));
}

int C(int N, int K) {
    return mult(f[N], mult(rf[K], rf[N - K]));
}

void solve() {
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] == '1');
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] && i + 1 < n && a[i + 1]) {
            cnt1++;
            i++;
            continue;
        }
        if (a[i] && i + 1 < n) {
            cnt2++;
            i++;
            continue;
        }
        if (a[i]) {
            continue;
        }
        cnt2++;
    }
//    cout << cnt1 << " " << cnt2 << "\n";
    cout << C(cnt1 + cnt2, cnt1) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    f[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = mult(f[i - 1], i);
    }
//    cout << f[maxn - 1];
    rf[maxn - 1] = divv(1, f[maxn - 1]);
//    cout << rf[maxn - 1] << "\n";
    for (int i = maxn - 2; i >= 0; i--) {
        rf[i] = mult(rf[i + 1], i + 1);
    }
//    for (int i = 0; i < 10; i++) {
//        cout << "   " << f[i] << " " << rf[i] << "\n";
//    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}