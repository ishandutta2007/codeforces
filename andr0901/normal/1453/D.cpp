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

mt19937 rng(time(0));

void solve() {
    long long k;
    cin >> k;
    if (k % 2) {
        cout << "-1\n";
        return;
    }
    k /= 2;
    vector <int> ans;
    for (int i = 60; i > 0; --i) {
        if ((k >> i) & 1) {
            ans.pb(1);
            forn (j, 1, i)
                ans.pb(0);
            ans.pb(1);
        }
    }
    if (k % 2)
        ans.pb(1);
    cout << ans.size() << "\n" << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    /*vector <int> mask = {1, 0, 0, 0, 0, 0};
    int s = 0, ITERS = 100000;
    forn (_, 0, ITERS) {
        int i = 0, steps = 0;
        while (i != mask.size()) {
            int t = rng() % 2;
            if (t == 0) {
                for (int j = i; ; --j) {
                    if (mask[j] == 1) {
                        i = j;
                        break;
                    }
                }
            } else {
                ++i;
            }
            ++steps;
        }
        s += steps;
    }
    cout << fixed << setprecision(2) << 1.0 * s / ITERS;*/
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}