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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> pr(n + k + 1);
    forn (i, 0, n)
        pr[i + 1] = pr[i] + (s[i] == '1');
    forn (i, n + 1, n + k + 1)
        pr[i] = pr[i - 1];
    int ans = 1e9, cnt = 0;
    vector <int> sf(n + k);
    for (int i = n - 1; i >= 0; --i) {
        sf[i] = (s[i] != '1') + min(sf[i + k] + pr[i + k] - pr[i + 1], cnt);
        chkmin(ans, pr[i] + sf[i]);
        cnt += (s[i] == '1');
    }
    cout << min(ans, cnt) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}