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
    int n;
    cin >> n;
    deque <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    vector <int> prev(2), ans(2);
    forn (i, 0, n + 1) {
        int turn = i % 2, cur = 0;
        if (turn == 0) {
            while (!a.empty() && cur <= prev[turn ^ 1]) {
                cur += a.front();
                a.pop_front();
            }
        } else {
            while (!a.empty() && cur <= prev[turn ^ 1]) {
                cur += a.back();
                a.pop_back();
            }
        }
        ans[turn] += cur;
        prev[turn] = cur;
        if (a.empty()) {
            cout << i + 1 << " " << ans << "\n";
            return;
        }
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