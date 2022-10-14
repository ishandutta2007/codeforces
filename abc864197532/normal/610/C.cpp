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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 0) {
        cout << '+' << endl;
    } else {
        vector <string> ans = {"++", "+*"};
        while (n > 1) {
            int m = ans.size();
            vector <string> cur;
            fop (i,0,m) {
                string a, b;
                fop (j,0,m) {
                    a.pb(ans[i][j]);
                    a.pb(ans[i][j]);
                    if (ans[i][j] == '+') {
                        b += "*+";
                    } else {
                        b += "+*";
                    }
                }
                cur.pb(a);
                cur.pb(b);
            }
            swap(ans, cur);
            n--;
        }
        for (string s : ans) cout << s << endl;
    }
    /*
     * ++
     * +-
     * ++--
     * +--+
     * +-+-
     * ++++
     *
     *
     * +++----
     * +--++--
     * +----++
     * -+-+-+-
     * -+--+-+
     * --++--+
     * --+-++-
     */
}