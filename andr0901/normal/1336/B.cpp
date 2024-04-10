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

void solve() {
    vector <int> sizes(3);
    cin >> sizes;
    vector <vector <int>> a(3);
    forn (i, 0, 3) {
        a[i].resize(sizes[i]);
        cin >> a[i];
        sort(all(a[i]));
    }
    vector <int> p(3);
    iota(all(p), 0);
    long long ans = 4e18;
    do {
        auto b = a;
        forn (i, 0, 3)
            b[i] = a[p[i]];
        for (int x : b[0]) {
            auto Y = upper_bound(all(b[1]), x);
            if (Y == b[1].begin())
                continue;
            auto Z = lower_bound(all(b[2]), x);
            if (Z == b[2].end())
                continue;
            int y = *(--Y), z = *Z; 
            chkmin(ans, 1LL * (x - y) * (x - y) +
                        1LL * (y - z) * (y - z) + 
                        1LL * (z - x) * (z - x));
        }
    } while (next_permutation(all(p)));
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