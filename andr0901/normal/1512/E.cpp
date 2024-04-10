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

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int k = r - l + 1;
    vector<int> a(k);
    iota(all(a), 1);
    int cur = accumulate(all(a), 0);
    for (int i = k - 1; i >= 0; --i) {
        while (cur < s &&
               a[i] < n && 
               (i == k - 1 || a[i] + 1 < a[i + 1])) {
            ++a[i];
            ++cur;
        }
    }
    if (cur != s) {
        cout << "-1\n";
        return;
    }
    set<int> not_used;
    forn (i, 1, n + 1)
        not_used.insert(i);
    vector<int> ans(n);
    for (int i = l - 1, j = 0; j < k; ++i, ++j) {
        ans[i] = a[j];
        not_used.erase(a[j]);
    }
    forn (i, 0, n) {
        if (ans[i] == 0) {
            ans[i] = *not_used.begin();
            not_used.erase(not_used.begin());
        }
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