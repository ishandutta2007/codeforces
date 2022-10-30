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
    vector <int> a(n), b(m);
    forn (i, 0, n)
        cin >> a[i];
    map <int, int> rev;
    forn (i, 0, m) {
        cin >> b[i];
        rev[b[i]] = i;
    }
    forn (i, 0, n) {
        if (rev.find(a[i]) == rev.end())
            rev[a[i]] = 1e9;
        a[i] = rev[a[i]];
        //cout << a[i] << " ";
    }
    long long ans = 0;
    int j = 0;
    multiset <int> sorted;
    forn (i, 0, m) {
        if (sorted.find(i) != sorted.end()) {
            ans++;
            sorted.erase(sorted.find(i));
        } else {
            int iters = 0;
            while (sorted.find(i) == sorted.end()) {
                sorted.insert(a[j++]);
                iters++;
            }
            ans += 2 * sorted.size() - 1;
            sorted.erase(sorted.find(i));
        }
        //cout << j << " " << ans << " "  << sorted.size() << "\n";
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