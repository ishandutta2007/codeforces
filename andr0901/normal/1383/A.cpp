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
    cin >> n;
    string a, b;
    cin >> a >> b;
    forn (i, 0, n)
        a[i] -= 'a', b[i] -= 'a';
    vector <vector <int>> cnt(20, vector <int> (20));
    forn (i, 0, n)
        cnt[a[i]][b[i]]++;
    forn (i, 0, n)
        if (a[i] > b[i]) {
            cout << "-1\n";
            return;
        }
    int ans = 0;
    for (int i = 0; i < 20; ) {
        int mn = -1;
        forn (j, i + 1, 20)
            if (cnt[i][j]) {
                mn = j;
                break;
            }
        cerr << i << " " << mn << "\n";
        if (mn == -1) {
            ++i;
            continue;
        }
        ++ans;
        cnt[i][mn] = 0;
        forn (j, mn + 1, 20) {
            cnt[mn][j] += cnt[i][j];
            cnt[i][j] = 0;
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