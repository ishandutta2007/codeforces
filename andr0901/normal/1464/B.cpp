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

#define int long long

int ans = 4e18;

void solve(string& s, int x, int y) {
    int cur = 0;
    int n = s.size();
    vector <int> cnt(2);
    forn (i, 0, n) {
        if (s[i] == '0') {
            cur += cnt[1] * y;
            cnt[0]++;
        } else {
            cur += cnt[0] * x;
            cnt[1]++;
        }
    }
    chkmin(ans, cur);
    cerr << cur << "  ";
    vector <vector <int>> suf(n + 1, vector <int> (2));
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1];
        if (s[i] == '0')
            suf[i][0]++;
        else
            suf[i][1]++;
    }
    cnt = vector <int> (2);
    forn (i, 0, n) {
        if (s[i] == '0') {
            cnt[0]++;
        } else if (s[i] == '1') {
            cnt[1]++;
        } else if (s[i] == '?') {
            cur -= cnt[0] * x;
            cur += cnt[1] * y;
            cur -= suf[i + 1][0] * y;
            cur += suf[i + 1][1] * x;
            cnt[0]++;
        }
        chkmin(ans, cur);
        cerr << cur << " ";
    }
    cerr << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    solve(s, x, y);
    reverse(all(s));
    swap(x, y);
    solve(s, x, y);
    cout << ans;
    return 0;
}