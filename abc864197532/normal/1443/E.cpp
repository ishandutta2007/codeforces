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
const int mod = 1e9 + 7, x = 864197532, N = 10008, logN = 18, K = 500, C = 100;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    lli now_move = 0, fac[16];
    fac[0] = 1;
    fop (i,1,16) fac[i] = fac[i - 1] * i;
    auto sum = [&](int x) {
        vector <int> cur(min(n, 16), 0);
        int m = cur.size();
        lli k = now_move;
        vector <bool> is(m + 1, false);
        is[0] = true;
        int front = n - m;
        fop (i,0,m) {
            vector <int> tmp;
            fop (i,0,m + 1) if (!is[i]) tmp.pb(i);
            int cnt = 0;
            while (k >= fac[m - i - 1]) {
                cnt++;
                k -= fac[m - i - 1];
            }
            cur[i] = tmp[cnt];
            is[cur[i]] = true;
            cur[i] += n - m;
        }
        if (x <= front) return 1ll * x * (x + 1) / 2;
        return 1ll * front * (front + 1) / 2 + accumulate(cur.begin(), cur.begin() + x - front, 0ll);
    };
    while (q--) {
        int t, l, r;
        cin >> t >> l;
        if (t == 1) {
            cin >> r;
            cout << sum(r) - sum(l - 1) << endl;
        } else {
            now_move += l;
        }
    }
}