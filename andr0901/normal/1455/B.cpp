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

map <int, int> bad;

void solve() {
    int x;
    cin >> x;
    if (bad.find(x) != bad.end()) {
        cout << bad[x] << "\n";
        return;
    }
    int s = 0;
    forn (i, 0, 2e3 + 5) {
        s += i;
        if (s >= x) {
            cout << i    << "\n";
            return;
        }        
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int s = 0;
    forn (i, 1, 2e3 + 5) {
        s += i;
        bad[s - 1] = i + 1;
    }
    map <int, bool> used;
    used[0] = true;
    forn (i, 1, 15) {
        map <int, bool> new_used;
        for (auto [j, t] : used)
            new_used[j + i] = new_used[j - 1] = true;
        used = new_used;
        cerr << i << ": ";
        for (auto j : used)
            cerr << j.fs << " ";
        cerr << "\n";
    }
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}