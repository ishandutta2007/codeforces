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
    int m;
    cin >> s >> m;
    int n = sz(s);
    vector <int> cnt(26);
    forn (i, 0, n)
        cnt[s[i] - 'a']++;
    vector <int> b(m);
    cin >> b;
    int lst = 25;
    string ans(m, '#');
    while (true) {
    //forn (i, 0, 2) {
        vector <int> zeroes;
        forn (i, 0, m)
            if (b[i] == 0)
                zeroes.pb(i);
        if (zeroes.empty())
            break;
        while (cnt[lst] < sz(zeroes))
            lst--;
        for (int i : zeroes) {
            ans[i] = (char)(lst + 'a');
            forn (j, 0, m)
                if (b[j] > 0)
                    b[j] -= abs(j - i);
        }
        for (int i : zeroes)
            b[i] = -1;
        lst--;
        cerr << ans << "\n";
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