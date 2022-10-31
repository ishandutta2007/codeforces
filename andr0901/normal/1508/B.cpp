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
template <typename T> ostream& operator<<(ostream& out, vector <T> a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

void solve(int n, long long k, vector<int>& ans, int lst = 1) {
    // cerr << n << " " << k << " " << lst << "\n" << ans << "\n---\n";
    if (n == 0) {
        return;
    }
    if (n > 62) {
        ans.pb(lst);
        solve(n - 1, k, ans, lst + 1);
        return;
    }
    forn (i, 0, n) {
        int cur = lst + i;
        long long t = (i == n - 1 ? 1 : (1LL << (n - i - 2)));
        if (k <= t) {
            for (int j = cur; j >= lst; --j) {
                ans.pb(j);
            }
            solve(n - i - 1, k, ans, cur + 1);
            return;
        }
        k -= t;
    }
    cerr << "kek\n";
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> ans;
    solve(n, k, ans);
    cerr << "---------\n";
    cout << (ans.size() < n ? vector<int>(1, -1) : ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}