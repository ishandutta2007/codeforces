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

vector <pii> ans;

void equalize(vector <int> x) {
    vector <vector <int>> a(sz(x));
    forn (i, 0, sz(x))
        a[i] = {x[i]};
    forn (i, 0, 100) {
        int p = sz(a);
        if (p == 1)
            return;
        vector <vector <int>> new_a(p / 2);
        for (int j = 0; j < p; j += 2) {
            forn (k, 0, sz(a[j])) {
                ans.eb(a[j][k], a[j + 1][k]);
                new_a[j / 2].pb(a[j][k]);
                new_a[j / 2].pb(a[j + 1][k]);
            }
        }
        a = new_a;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int p = 1;
    while (p < n)
        p *= 2;
    p /= 2;
    vector <int> x;
    forn (i, 1, p + 1)
        x.pb(i);
    vector <int> y;
    for (int i = n; i > n - p; --i)
        y.pb(i);
    equalize(x), equalize(y);
    cout << sz(ans) << "\n";
    for (auto i : ans)
        cout << i.fs << " " << i.sc << "\n";
    return 0;
}