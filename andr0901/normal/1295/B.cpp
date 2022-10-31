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

void solve() {
    int n, x;
    cin >> n >> x;
    vector <int> a(n + 1);
    forn (i, 0, n) {
        char c;
        cin >> c;
        if (c == '0')
            a[i + 1] = a[i] + 1;
        else
            a[i + 1] = a[i] - 1;
    }
    if (a[n] == 0) {
        forn (i, 0, n + 1)
            if (a[i] == x) {
                cout << "-1\n";
                return;
            }
        cout << "0\n";
        return;
    }
    int ans = 0;
    forn (i, 0, n) {
        if ((x - a[i]) % a[n])
            continue;
        if ((x - a[i]) / a[n] < 0)
            continue;
        //cout << i << " " << a[i] << "\n";
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}