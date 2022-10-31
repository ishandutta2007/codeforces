#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 5e5 + 5;
int a[maxn], pref[maxn], n, ok[maxn];

inline void check(int k) {
    for (int i = 1; i <= n - k + 1; ++i) {
        if (pref[i + k - 1] - pref[i - 1] <= 0) return;
    }
    cout << k << '\n';
    exit(0);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, best = 1, good;
    cin >> n;
    good = n;
    for (int i = 1; i <= (n + 1) / 2; ++i) cin >> a[i];
    cin >> x;
    for (int i = (n + 1) / 2 + 1; i <= n; ++i) a[i] = x;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    if (pref[n] > 0) {
        cout << n << '\n';
        exit(0);
    }
    for (int i = 1; i <= n; ++i) if (pref[i] > 0) ok[i]++;
    for (int i = n; i >= 1; --i) if (pref[n] - pref[i - 1] > 0) ok[n - i + 1]++;
    vector < int > ask;
    for (int i = 1; i <= n; ++i) if (ok[i] == 2) ask.push_back(i);
    random_shuffle(ask.begin(), ask.end());
    for (auto key : ask) {
        check(key);
        if (1.0 * clock() / CLOCKS_PER_SEC > 1.9) {
            cout << -1;
            exit(0);
        }
    }
    cout << -1;
    return 0;
}