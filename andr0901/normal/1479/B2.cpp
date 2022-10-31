//#pragma GCC optimize("Ofast")
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> idxs(n + 1);
    forn (i, 0, n) {
        --a[i];
        idxs[a[i]].pb(i);
    }
    forn (i, 0, n + 1)
        idxs[i].pb(n);
    int ans = 0;
    vector<int> cur(2, n);
    forn (i, 0, n) {
        if (cur[0] == a[i] && cur[1] == a[i]) {
            continue;
        } else if (cur[0] == a[i] && cur[1] != a[i]) {
            cur[0] = a[i];
        } else if (cur[0] != a[i] && cur[1] == a[i]) {
            cur[1] = a[i];
        } else {
            if (*upper_bound(all(idxs[cur[0]]), i) > *upper_bound(all(idxs[cur[1]]), i)) {
                cur[0] = a[i];
                ++ans;
            } else {
                cur[1] = a[i];
                ++ans;
            }
        }
        cerr << cur << "\n";
    }
    cout << ans << "\n";
    return 0;
}