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

void solve() {
    int n, k;
    cin >> n >> k;
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    int init_k = k;
    if (l2 < r1) {
        if (r1 < r2)
            k -= (r1 - l2) * n;
        else
            k -= (r2 - l2) * n;
    }
    if (k <= 0) {
        cout << "0\n";
        return; 
    }
    int ans = 1e18, cur = 0;
    forn (i, 1, n + 1) {
        if (k < 0)
            break;
        int connect = 0;
        if (r1 < l2)
            connect += l2 - r1;
        int len = max(r1, r2) - min(l1, l2);
        if (r1 > l2) {
            int inter;
            if (r1 < r2) {
                inter = r1 - l2;
            } else {
                inter = r2 - l2;
            }
            len -= inter;
        }
        cerr << k << " " << len << " ";
        if (k < 0)
            break;
        if (k < len) {
            chkmin(ans, cur + connect + k);
            break;
        } else {
            k -= len;
            // cerr << k << " ";
            chkmin(ans, cur + connect + len + 2 * k);
            cur += connect + len;
        }
        // cerr << connect << " " << cur << " " << connect << " " << ans << "\n";
    }
    cout << ans << "\n";
}
// [1, 1] [3, 3]
// [1, 3] [3, 3] + 2
// [3, 3] [3, 3] + 2


main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}

/*
l1 r1 l2 r2
l1 l2 r1 r2
l1 l2 r2 r1
*/