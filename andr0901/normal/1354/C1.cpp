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

const double PI = atan2(0, -1);

void solve() {
    int n;
    cin >> n;
    n *= 2;
    ld r = 1 / (2 * sin(PI / n));
    vector <pair <ld, ld>> points;
    ld alpha = 2 * PI / n;
    forn (i, 0, n) {
        pair <ld, ld> cur = {r * cos(alpha * i), r * sin(alpha * i)};
        if (cur.fs >= 0 && cur.sc >= 0)
            points.pb(cur);
    }
    /*for (auto [x, y] : points)
        cout << x << " " << y << "\n";*/
    auto check = [&](ld M) -> bool {
        for (auto [x, y] : points)
            if (y > M - x)
                return false;
        return true;
    };
    ld L = 0, R = 1e9;
    forn (i, 0, 100) {
        ld M = (L + R) / 2;
        if (check(M))
            R = M;
        else
            L = M;
    }
    ld ans = L;

    points.clear();
    forn (i, 0, n) {
        pair <ld, ld> cur = {r * cos(alpha * i + alpha / 2), r * sin(alpha * i + alpha / 2)};
        if (cur.fs >= 0 && cur.sc >= 0)
            points.pb(cur);
    }
    L = 0, R = 1e9;
    forn (i, 0, 100) {
        ld M = (L + R) / 2;
        if (check(M))
            R = M;
        else
            L = M;
    }
    chkmin(ans, L);
    cout << fixed << setprecision(10) << sqrt(2) * ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}