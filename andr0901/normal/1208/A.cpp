#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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
    int a, b, n;
    cin >> a >> b >> n;
    vector <int> history;
    set <int> was;
    forn (i, 0, n) {
        int c = (a ^ b);
        if (was.find(c) != was.end()) {
            cout << history[(n + 1) % was.size()] << "\n";
            return;
        }
        else {
            history.pb(c);
            was.insert(c);
            a = b;
            b = c;
        }
    }
    cout << a << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) 
        solve();
    return 0;
}