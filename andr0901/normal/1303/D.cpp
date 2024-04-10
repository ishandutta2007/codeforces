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
    long long m;
    int n;
    cin >> m >> n;
    unordered_map <long long, int> get;
    forn (i, 0, 61)
        get[(1LL << i)] = i;
    vector <int> a(62);
    forn (i, 0, n) {
        long long x;
        cin >> x;
        a[get[x]]++;
    }
    int ans = 0;
    forn (i, 0, 61) {
        if (((m >> i) & 1) == 0) {
            a[i + 1] += a[i] / 2;
            continue;
        }
        if (!a[i]) {
            bool ok = false;
            forn (j, i, 61) {
                if (a[j]) {
                    ans += j - i;
                    a[j]--;
                    forn (k, i, j)
                        a[k]++;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "-1\n";
                return;
            }
        }
        a[i + 1] += (a[i] - 1) / 2;
        /*forn (i, 0, 10)
            cout << a[i] << " ";
        cout << "\n";*/
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