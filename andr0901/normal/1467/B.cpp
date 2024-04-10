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

constexpr int INF = 1e9;

bool is_good(int a, int b, int c) {
    return a > b && b < c ||
           a < b && b > c;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> good(n);
    forn (i, 1, n - 1)
        good[i] = is_good(a[i - 1], a[i], a[i + 1]);
    int s = accumulate(all(good), 0);
    int ans = s;
    forn (i, 0, n) {
        vector<int> possible = {-INF - 1, INF + 1};
        if (i - 1 >= 0) {
            possible.pb(a[i - 1] - 1);
            possible.pb(a[i - 1]);
            possible.pb(a[i - 1] + 1);
        }
        if (i + 1 < n) {
            possible.pb(a[i + 1] - 1);
            possible.pb(a[i + 1]);
            possible.pb(a[i + 1] + 1);
        }
        for (int x : possible) {
            int cur = s;
            cur -= good[i];
            if (i - 1 >= 0) {
                cur -= good[i - 1];
            }
            if (i + 1 < n) {
                cur -= good[i + 1];
            }
            int t = x;
            if (i - 1 >= 0 && i + 1 < n) {
                cur += is_good(a[i - 1], t, a[i + 1]);
            }
            if (i - 2 >= 0) {
                cur += is_good(a[i - 2], a[i - 1], t);
            }
            if (i + 2 < n) {
                cur += is_good(t, a[i + 1], a[i + 2]);
            }
            chkmin(ans, cur);
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