#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1001, logN = 18, K = 500, C = 1e9;

void solve() {
    int n;
    cin >> n;
    string s[n];
    fop (i,0,n) cin >> s[i];
    int cnt[6]{}, t = 0;
    vector <int> p(3);
    iota(all(p), 0); // 0 -> O, 1 -> X, 2 -> no
    do {
        fop (i,0,n) fop (j,0,n) {
            if ((i + j) % 3 == p[0] && s[i][j] == 'X') cnt[t]++;
            if ((i + j) % 3 == p[1] && s[i][j] == 'O') cnt[t]++;
        }
        t++;
    } while (next_permutation(all(p)));
    int mn = min_element(cnt, cnt + 6) - cnt;
    sort(all(p));
    do {
        if (!mn) break;
        mn--;
    } while (next_permutation(all(p)));
    fop (i,0,n) {
        fop (j,0,n) {
            if ((i + j) % 3 == p[0] && s[i][j] == 'X') s[i][j] = 'O';
            if ((i + j) % 3 == p[1] && s[i][j] == 'O') s[i][j] = 'X';
        }
        cout << s[i] << endl;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}