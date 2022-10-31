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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    forn (i, 0, n)
        s[i] -= 'a';
    vector <vector <int>> pr(n, vector <int> (26));
    forn (i, 0, n) {
        pr[i][s[i]] = 1;
        if (!i)
            continue;
        forn (j, 0, 26)
            pr[i][j] += pr[i - 1][j];
    }
    vector <int> a(m), ans(26);
    forn (i, 0, 26)
        ans[i] = pr[n - 1][i];
    forn (i, 0, m) {
        cin >> a[i];
        forn (j, 0, 26)
            ans[j] += pr[a[i] - 1][j];
    }
    for (int i : ans)
        cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}