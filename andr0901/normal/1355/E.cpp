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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    c = min(c, a + b);
    vector <int> bricks(n);
    cin >> bricks;
    sort(all(bricks));
    auto get = [&](int x) -> long long {
        long long less = 0, greater = 0;
        forn (i, 0, n) {
            if (bricks[i] < x) {
                less += x - bricks[i];
            } else {
                greater += bricks[i] - x;
            }
        }
        long long t = min(less, greater);
        less -= t, greater -= t;
        return less * a + greater * b + t * c;
    };
    int l = 0, r = 1e9;
    while (r - l > 2) {
        int m1 = l + (r - l) / 3, m2 = l + 2 * (r - l) / 3; 
        if (get(m1) < get(m2))
            r = m2;
        else
            l = m1;
    }
    long long ans = 1e18;
    forn (i, l, r + 1)
        chkmin(ans, get(i));
    cout << ans;
    return 0;
}