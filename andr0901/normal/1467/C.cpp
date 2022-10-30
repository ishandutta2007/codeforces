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
    vector<int> sizes(3);
    cin >> sizes;
    vector<vector<int>> a(3);
    forn (i, 0, 3)
        a[i].resize(sizes[i]);
    cin >> a;
    int s = 0;
    forn (i, 0, 3)
        s += accumulate(all(a[i]), 0LL);
    int ans = 0;
    forn (i, 0, 3) {
        int cur = s;
        forn (j, 0, 3)
            if (i != j)
                cur -= 2 * *min_element(all(a[j]));
        chkmax(ans, cur);
        chkmax(ans, s - 2 * accumulate(all(a[i]), 0LL));
    }
    cout << ans;
    return 0;
}