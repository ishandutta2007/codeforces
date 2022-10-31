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
    vector<vector<int>> ans(n, vector<int> (n, -1));
    if (n % 2) {
        int wins = n / 2;
        forn (i, 0, n) {
            forn (j, 0, wins) {
                ans[i][(i + 1 + j) % n] = 1;  
            }
        }
    } else {
        int wins = (n - 1) / 2;
        forn (i, 0, n) {
            forn (j, 0, wins) {
                ans[i][(i + 1 + j) % n] = 1;  
            }
            ans[i][(i + 1 + wins) % n] = 0;
        }
    }
    forn (i, 0, n) {
        forn (j, i + 1, n) {
            cout << ans[i][j] << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}