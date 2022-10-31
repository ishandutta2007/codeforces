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

long long get(const string& s, int idx) {
    long long ans = 0;
    int lst = idx - 1;
    for (int i = idx - 1; i >= 0; --i) {
        if (s[i] == '*') {
            ans += lst - i;
            --lst;
        }
    }
    lst = idx + 1;
    for (int i = idx + 1; i < s.size(); ++i) {
        if (s[i] == '*') {
            ans += i - lst;
            ++lst;
        }
    }
    cerr << idx << ": " <<  ans << "\n";
    return ans;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (char c : s) {
        if (c == '*') {
            ++cnt;
        }
    }
    if (cnt == 0) {
        cout << "0\n";
        return;
    }
    long long ans = 1e18;
    int cur = 0;
    forn (i, 0, sz(s)) {
        if (s[i] == '*') {
            ++cur;
        }
        if (s[i] == '*' && 
            (cur == cnt / 2 || cur == (cnt + 1) / 2)) {
            chkmin(ans, get(s, i));
        }
    }
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