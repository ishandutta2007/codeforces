#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

void transform(string& s) {
    forn (i, 0, sz(s))
        s[i] -= '0';
    reverse(all(s));
}

void solve() {
    string a, b;
    cin >> a >> b;
    transform(a), transform(b);
    int idx;
    forn (i, 0, sz(b)) {
        if (b[i] == 1) {
            idx = i;
            break;
        }
    }
    forn (i, idx, sz(a)) {
        if (a[i] == 1) {
            cout << i - idx << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}