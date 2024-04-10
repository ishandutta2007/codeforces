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

pii get() {
    int a, b;
    cin >> a >> b;
    return {a, b};
}

void solve() {
    pii a = get(), b = get(), x = get();
    if (a.fs == b.fs && a.fs == x.fs) {
        int l = min(a.sc, b.sc);
        int r = max(a.sc, b.sc);
        if (l <= x.sc && x.sc <= r) {
            cout << r - l + 2;
        } else {
            cout << r - l;
        }
    } else if (a.sc == b.sc && a.sc == x.sc) {
        int l = min(a.fs, b.fs);
        int r = max(a.fs, b.fs);
        if (l <= x.fs && x.fs <= r) {
            cout << r - l + 2;
        } else {
            cout << r - l;
        }
    } else {
        cout << abs(a.fs - b.fs) + abs(a.sc - b.sc);
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