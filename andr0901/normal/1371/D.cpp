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
    int n, k;
    cin >> n >> k;
    k = n * n - k;
    vector <vector <int>> ans(n, vector <int> (n, 1));
    forn (i, 0, n) {
        if (!k)
            break;
        forn (j, 0, n) {
            if (!k)
                break;
            ans[j][(i + j) % n] = 0;
            --k;
        }
    }
    int f = 0;
    vector <int> r(n), c(n);
    forn (i, 0, n) {
        forn (j, 0, n) {
            r[i] += ans[i][j];
            c[j] += ans[i][j];
        }
    }
    int mx_r = *max_element(all(r)), mn_r = *min_element(all(r));
    int mx_c = *max_element(all(c)), mn_c = *min_element(all(c));     
    cout << 1LL * (mx_r - mn_r) * (mx_r - mn_r) + 
            1LL * (mx_c - mn_c) * (mx_c - mn_c) << "\n";
    forn (i, 0, n) {
        forn (j, 0, n)
            cout << ans[i][j];
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}