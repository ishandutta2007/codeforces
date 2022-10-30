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

int n;

bool found(const vector <string>& a, int i) {
    forn (j, 0, n)
        if (i != j && a[i] == a[j])
            return true;    
    return false;
}

void solve() {
    cin >> n;
    vector <string> a(n);
    forn (i, 0, n)
        cin >> a[i];
    int ans = 0;
    forn (i, 0, n) {
        if (!found(a, i))
            continue;
        forn (j, 0, 4) {
            bool to_break = false;
            forn (k, 0, 10) {
                a[i][j] = static_cast <char> (k + '0');
                if (!found(a, i)) {
                    ans++;
                    to_break = true;
                    break;
                }
            }
            if (to_break)
                break;
        }
    }
    cout << ans << "\n";
    for (auto& i : a)
        cout << i << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}