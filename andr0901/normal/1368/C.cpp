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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> ans;
    ans.eb(0, 0);
    ans.eb(0, 1);
    ans.eb(1, 0);
    forn (i, 1, n) {
        ans.eb(i, i);
        ans.eb(i, i + 1);
        ans.eb(i + 1, i);
    }
    ans.eb(n, n);
    ans.eb(n, n + 1);
    ans.eb(n + 1, n);
    ans.eb(n + 1, n + 1);
    cout << sz(ans) << "\n";
    forn (i, 0, sz(ans))
        cout << ans[i].fs << " " << ans[i].sc << "\n";
    return 0;
}