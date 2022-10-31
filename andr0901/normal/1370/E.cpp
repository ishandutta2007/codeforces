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
    string a, b;
    cin >> a >> b;
    int cnt_x = 0, cnt_y = 0;
    set <int> x, y;
    forn (i, 0, n) {
        if (a[i] == '0' && b[i] == '1') {
            x.insert(i);
        }
        if (a[i] == '1' && b[i] == '0') {
            y.insert(i);
        }
    }
    if (sz(x) != sz(y))
        return cout << -1, 0;
    int ans = 0;
    while (true) {
        int lst = -1;
        if (*x.begin() < *y.begin()) {
            while (true) {
                auto i = x.upper_bound(lst);
                if (i == x.end())
                    break;
                auto j = y.upper_bound(*i);
                if (j == y.end())
                    break;
                lst = *j;
                x.erase(i), y.erase(j);
            }
        } else {
            while (true) {
                auto i = y.upper_bound(lst);
                if (i == y.end())
                    break;
                auto j = x.upper_bound(*i);
                if (j == x.end())
                    break;
                lst = *j;
                y.erase(i), x.erase(j);
            }
        }
        if (lst == -1)
            break;
        ans++;
    }
    cout << ans;
    return 0;
}