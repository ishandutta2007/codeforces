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

vector <pii> a;
set <int> banned;
vector <int> ans;

void gen(int i, int prod) {
    if (i == sz(a)) {
        if (banned.find(prod) == banned.end())
            ans.pb(prod);
    } else {
        forn (j, 0, a[i].sc + 1) {
            gen(i + 1, prod);
            prod *= a[i].fs;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    a.clear();
    banned.clear();
    banned.insert(1);
    ans.clear();
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            a.eb(i, 0);
            while (n % i == 0) {
                a.back().sc++;
                n /= i;
            }
        }
    }
    if (n > 1)
        a.eb(n, 1);
    if (sz(a) == 1) {
        int prev = a[0].fs;
        forn (i, 1, a[0].sc + 1) {
            ans.pb(prev);
            prev *= a[0].fs;
        }
    } else if (sz(a) == 2) {
        if (a[0].sc > a[1].sc)
            swap(a[0], a[1]);
        ans.pb(a[0].fs);
        banned.insert(a[0].fs), banned.insert(a[0].fs * a[1].fs), banned.insert(a[1].fs);
        if (a[1].sc > 1)
            banned.insert(a[0].fs * a[1].fs * a[1].fs);
        int cur = a[0].fs;
        forn (j, 1, a[0].sc + 1) {
            gen(1, cur);
            cur *= a[0].fs;
        }
        ans.pb(a[0].fs * a[1].fs), ans.pb(a[1].fs);
        cur = a[1].fs;
        forn (j, 1, a[1].sc + 1) {
            gen(2, cur);
            cur *= a[1].fs;
        }
        if (a[1].sc > 1)
            ans.pb(a[0].fs * a[1].fs * a[1].fs);
    } else {
        banned.insert(a[0].fs * a.back().fs);
        forn (i, 0, sz(a)) {
            banned.insert(a[i].fs * (a[(i + 1) % sz(a)].fs));
            int cur = a[i].fs;
            forn (j, 1, a[i].sc + 1) {
                gen(i + 1, cur);
                cur *= a[i].fs;
            }
            ans.pb(a[i].fs * (a[(i + 1) % sz(a)].fs));
        }
    }
    int cnt = 0;
    forn (i, 0, sz(ans))
        cnt += (gcd(ans[i], ans[(i + 1) % sz(ans)]) == 1);
    cout << ans << "\n" << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}