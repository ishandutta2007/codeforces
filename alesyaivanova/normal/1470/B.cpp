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

const int maxn = 3e5 + 9;
int a[maxn];
int n;
const int T = 1e6 + 9;
int mn[T];

void solve() {
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        int x = 1;
        while (u > 1) {
            int y = mn[u];
            u /= y;
            if (u % y == 0)
                u /= y;
            else
                x *= y;
        }
        cnt[x]++;
    }
    int ma1 = 0, ma2 = 0, kek = cnt[1];
    for (pii x : cnt) {
        if (x.ss > ma1)
            ma1 = x.ss;
        if (x.ff == 1)
            continue;
        if (x.ss % 2 == 0)
            kek += x.ss;
        else
            ma2 = max(ma2, x.ss);
    }
    ma2 = max(ma2, kek);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int w;
        cin >> w;
        if (!w)
            cout << ma1 << "\n";
        else
            cout << ma2 << "\n";
    }
}

void prec() {
    vector<int> primes;
    for (int i = 2; i < T; i++)
        mn[i] = i;
    for (int i = 2; i < T; i++) {
        if (mn[i] == i)
            primes.pb(i);
        for (int e : primes) {
            if (e > mn[i] || i * e >= T)
                break;
            mn[i * e] = e;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    prec();
    int t;
    cin >> t;
    while (t--)
        solve();
}