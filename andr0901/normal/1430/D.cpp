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
    int n;
    string s;
    cin >> n >> s;
    vector <int> blocks;
    int cnt = 0;
    forn (i, 0, sz(s)) {
        ++cnt;
        if (i + 1 == s.size() || s[i] != s[i + 1]) {
            blocks.pb(cnt);
            cnt = 0;
        }
    }
    int i = 0, j = 0;
    int ans = 0;
    while (i < sz(blocks)) {
        ++ans;
        if (blocks[i] > 1) {
            blocks[i] = 0;
            ++i;
            continue;
        }
        while (j < sz(blocks) && blocks[j] < 2)
            ++j;
        if (j != sz(blocks)) {
            --blocks[j];
        } else {
            blocks[i] = 0;
            ++i;
            if (i == blocks.size())
                break;
        }
        blocks[i] = 0;
        ++i;
    }
    /*cerr << blocks << "\n";
    int ans = 0;
    while (!s.empty()) {
        ++ans;
        if (s.size() <= 2)
            break;
        int back = s.size() - 1;
        if (s[back] == s[back - 1]) {
            auto t = s[back];
            while (!s.empty() && s.back() == t)
                s.pop_back();
        } else {
            s.pop_back();
            s.pop_back();
        }
    }*/
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