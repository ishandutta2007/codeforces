#include <bits/stdc++.h>

using namespace std;
#define int long long
#define f first
#define s second
const int INF = 1e15;

void gen(int n, vector <int> &a, vector <int> &b, vector <int> &c, vector <pair <int, int>> &fl, int now, int kek) {
    if (now == n) return;
    int flex = min(min(c[now - 1], fl[now].first), min(kek, b[now] - c[now]));
    c[now - 1] -= flex;
    c[now] += flex;
    fl[now].first -= flex;
    fl[now].second += flex;
    gen(n, a, b, c, fl, now + 1, min(kek - flex, min(fl[now].f, c[now - 1])));
    int flex1 = min(min(c[now - 1], fl[now].f), min(kek - flex, b[now] - c[now]));
    c[now - 1] -= flex1;
    c[now] += flex1;
    fl[now].f -= flex1;
    fl[now].s += flex;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        int ans = 0;
        vector <int> now(n);
        bool f = true;
        vector <pair <int, int>> kek(n);
        for (int i = 1; i < n; ++i) {
            int flex = min(b[i - 1] - now[i - 1], a[i]);
            now[i - 1] += flex;
            kek[i].first = flex;
            if (flex + b[i] < a[i]) {
                f = false;
                break;
            }
            now[i] += a[i] - flex;
            kek[i].second = a[i] - flex;
        }
        if (!f) {
            cout << "NO\n";
            continue;
        }
        gen(n, a, b, now, kek, 1, INF);
        if (b[0] - now[0] + b[n - 1] - now[n - 1] >= a[0]) cout << "YES\n";
        else cout << "NO\n";
    }
}