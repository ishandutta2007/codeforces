#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << endl;\
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
const int mod = 1e9 + 7, x = 864197532, N = 500005, logN = 18, K = 600, C = 100, M = 1e9;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector <int> v = {0, 1, 2, 0, 2, 1, 0};
    lli a[3];
    fop (i,0,3) cin >> a[i];
    lli ans = 0;
    fop (i,0,7) {
        lli b[3] = {a[0], a[1], a[2]};
        lli tmp = 0;
        fop (j,i,7) {
            if (b[v[j]] == 0) {
                break;
            } else {
                b[v[j]]--;
                tmp++;
            }
        }
        lli mn = min({b[0] / 3, b[1] / 2, b[2] / 2});
        tmp += mn * 7;
        b[0] -= mn * 3;
        b[1] -= mn * 2;
        b[2] -= mn * 2;
        int now = 0;
        while (1) {
            if (b[v[now]] == 0) {
                break;
            } else {
                b[v[now]]--;
            }
            tmp++;
            now = (now + 1) % 7;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}