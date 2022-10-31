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
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> ans(n, 2e9);
    forn (i, 0, n) {
        forn (j, i + 1, n) {
            if ((y - x) % (j - i))
                continue;
            vector <int> cur(n);
            int step = (y - x) / (j - i);
            cur[i] = x;
            for (int k = i - 1; k >= 0; --k)
                cur[k] = cur[k + 1] - step;
            forn (k, i + 1, n)
                cur[k] = cur[k - 1] + step;
            if (cur[0] <= 0)
                continue;
            if (cur.back() < ans.back())
                ans = cur;
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