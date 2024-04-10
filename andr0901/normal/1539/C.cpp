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

#define int long long

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    vector<int> diffs(n - 1);
    forn (i, 0, n - 1) {
        diffs[i] = a[i + 1] - a[i];
    }
    sort(all(diffs));
    cerr  << diffs << "\n";
    int ans = 1;
    forn (i, 0, n - 1) {
        int t = (diffs[i] - 1) / x;
        if (diffs[i] - 1 < 0) {
            t = 0;
        }
        cerr << t << " ";
        if (t == 0) {
            continue;
        }
        if (t <= k) {
            k -= t;
            continue;
        }
        ans++;
    }
    cout << ans << "\n";
    return 0;
}