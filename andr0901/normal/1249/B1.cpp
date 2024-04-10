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
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i], a[i]--;
    vector <int> sz_col(n + 1);
    vector <int> colors(n);
    int cur = 1;
    forn (i, 0, n) {
        if (!colors[i]) {
            int j = a[i];
            colors[i] = cur;
            sz_col[cur] = 1;
            while (j != i) {
                colors[j] = cur;
                sz_col[cur]++;
                j = a[j];
            }
            cur++;
        }
    }
    forn (i, 0, n) 
        cout << sz_col[colors[i]] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q --> 0)
        solve();
    return 0;
}