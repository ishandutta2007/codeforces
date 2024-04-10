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
    vector<int> a(n);
    cin >> a;
    auto check = [&](int m) {
        cerr << m << ":\n";
        vector<int> pr(n + 1);
        forn (i, 0, n)
            pr[i + 1] = pr[i] + (a[i] >= m ? 1 : -1);
        cerr << pr << "\n";
        int mn = 1e9;
        forn (i, k - 1, n + 1) {
            if (pr[i] - mn > 0) {
                cerr << i << "\n";
                return true;
            }
            chkmin(mn, pr[i - (k - 1)]);
        }
        return false;
    };
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t --> 0)
        solve();
    return 0;
}