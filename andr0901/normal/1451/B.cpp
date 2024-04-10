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
    int n, q;
    string s;
    cin >> n >> q >> s;
    while (q --> 0) {
        int l, r;
        cin >> l >> r;
        string t;
        forn (i, l - 1, r)
            t += s[i];
        vector <int> forward, backward;
        int lst = 0;
        forn (i, 0, n) {
            if (lst != t.size() && s[i] == t[lst]) {
                forward.pb(i);
                ++lst;
            }
        }
        lst = t.size() - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (lst != -1 && s[i] == t[lst]) {
                backward.pb(i);
                --lst;
            }
        }
        reverse(all(backward));
        if (lst == -1 && forward != backward)
            cout << "YES";
        else
            cout << "NO";
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