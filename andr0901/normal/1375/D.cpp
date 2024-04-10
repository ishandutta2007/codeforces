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
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    vector <int> cnt(n + 1);
    forn (i, 0, n)
        cnt[a[i]]++;
    auto mex = [&]() -> int {
        forn (i, 0, n + 1)
            if (cnt[i] == 0)
                return i;
    };
    vector <int> ans;
    auto apply = [&](int i) {
        int new_val = mex();
        cnt[a[i]]--;
        cnt[new_val]++;
        a[i] = new_val;
        ans.pb(i + 1);
    };
    forn (i, 0, 2 * n) {
        int j = mex();
        if (j == 0) {
            forn (k, 0, n)
                if (a[k] != k + 1 && a[k])
                    j = k + 1;
            if (!j)
                break;
        }
        apply(j - 1);
        cerr << j << ": " << a << "\n";
    }
    /*forn (i, 0, n) {
        if (cnt[a[i]] > 1) {
            apply(i);
        }
    }
    cerr << a << "\n";
    int m;
    if (mex() == n)
        apply(0);
    m = mex();
    apply(m - 1);
    cerr << a << "\n";
    forn (i, 0, n - 1) {
        int j = mex();
        if (j < m)
            apply(j);
        else
            apply(j - 1);
    }*/
    cerr << a << "\n";
    cout << sz(ans) << "\n" << ans << "\n";
    cerr << "---\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}