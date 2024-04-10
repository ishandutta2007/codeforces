#pragma GCC optimize("Ofast")
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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <int> a;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <vector <int>> levels(n);
    levels[n - 1].pb(0);
    int cur = 1;
    for (int i = n - 1; i >= 0; --i) {
        sort(all(levels[i]));
        for (int l : levels[i]) {
            int r = l + i;
            int m;
            if ((r - l + 1) % 2)
                m = (l + r) / 2;
            else
                m = (l + r - 1) / 2;
            a[m] = cur++;
            if ((m - 1) - l >= 0)
                levels[(m - 1) - l].pb(l);
            if (r - (m + 1) >= 0)
                levels[r - (m + 1)].pb(m + 1);
        }
    }
    cout << a << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}