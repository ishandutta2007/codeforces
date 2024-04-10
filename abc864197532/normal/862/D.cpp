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
const int mod = 998244353, x = 864197532, N = 100008, logN = 18, K = 500, C = 100;

int ask(string s) {
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int oall = ask(string(n, '0')), zall = n - oall;
    int ocur = oall, zcur = zall;
    int l = 0, r = n;
    int ans0 = 0, ans1 = 0;
    while (r - l > 1) {
        int mid = l + r >> 1;
        string s = string(n, '0');
        fop (i,l,mid) s[i] = '1';
        int nowone = ask(s);
        int tmp = (nowone + oall + mid - l) / 2;
        int o1 = tmp - nowone, z1 = tmp - oall, o2 = ocur - o1, z2 = zcur - z1;
        // cout << l << ' ' << mid << ' ' << o1 << ' ' << z1 << ' ' << o2 << ' ' << z2 << endl;
        bool is = true;
        if (o1 == 0 || z1 == 0) {
            if (o1 == 0) ans0 = l + 1;
            else ans1 = l + 1;
            l = mid;
            is = false;
            ocur = o2;
            zcur = z2;
        }
        if (o2 == 0 || z2 == 0) {
            if (o2 == 0) ans0 = mid + 1;
            else ans1 = mid + 1;
            if (is) {
                r = mid;
                is = false;
                ocur = o1;
                zcur = z1;
            }
        }
        if (is) {
            l = mid;
            ocur = o2;
            zcur = z2;
        }
    }
    // 101
    cout << "! " << ans0 << ' ' << ans1 << endl;
}