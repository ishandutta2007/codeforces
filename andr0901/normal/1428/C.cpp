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

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    int cnt_b = 0;
    for (int i = sz(s) - 1; i >= 0; --i) {
        cnt_b += (s[i] == 'B');
        if (s[i] == 'A' && cnt_b) {
            cnt_b--;
            ans += 2;
        }
    }
    cout << sz(s) - (ans + cnt_b / 2 * 2) << "\n";
    /*vector <int> blocks;
    int cnt = 1;
    forn (i, 1, sz(s)) {
        if (s[i] != s[i - 1]) {
            blocks.pb(cnt);
            cnt = 0;
        }
        ++cnt;
    }
    blocks.pb(cnt);
    int ans = 0;
    int i = 0;
    int cnt_b = 0;
    if (s[0] == 'B') {
        cnt_b += blocks[0];
        ++i;
    }
    cerr << blocks << "\n";
    for (; i + 1 < sz(blocks); i += 2) {
        int a = blocks[i], b = blocks[i + 1];
        int cur = min(a, b);
        ans += cur * 2;
        a -= cur, b -= cur;
        if (a == 0)
            cnt_b += b;
        else {
            ans += cnt_b / 2 * 2;
            cnt_b = 0;
        }
        // cerr << ans << " ";
    }
    ans += cnt_b / 2 * 2;
    cout << sz(s) - ans << "\n";*/
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}