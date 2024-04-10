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

void solve() {
    int n;
    long long w;
    cin >> n >> w;
    vector <pii> a(n);
    forn (i, 0, n) {
        cin >> a[i].fs;
        a[i].sc = i + 1;
    }
    sort(all(a));
    forn (i, 0, n)
        if ((w + 1) / 2 <= a[i].fs && a[i].fs <= w) {
            cout << "1\n" << a[i].sc << "\n";
            return;
        }
    long long pref = 0;
    forn (i, 0, n) {
        pref += a[i].fs;
        if ((w + 1) / 2 <= pref && pref <= w) {
            cout << i + 1 << "\n";
            forn (j, 0, i + 1)
                cout << a[j].sc << " ";
            cout << "\n";
            return;
        }
    }
    cout << "-1\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}