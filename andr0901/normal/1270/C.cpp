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
#define int long long

void solve() {
    int n;
    cin >> n;
    int s = 0, x = 0;
    forn (i, 0, n) {
        int t;
        cin >> t;
        s += t, x ^= t;
    }
    int t = 0;
    forn (i, 0, 52)
        if (((x >> i) & 1) == 0) {
            t ^= (1LL << i);
        }
    if ((s + t) % 2) {
        t++;
    }
    s += t, x ^= t;/*
    cout << s << " " << x << "\n";
    int y = (2 * x - s) / 2;
    s += y, s += y;
    if (s != 2 * x)
        cout << s << " " << 2 * x << "FUCK\n";
    else*/
        cout << "3\n" << t << " " << (2 * x - s) / 2 << " " << (2 * x - s) / 2 << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}