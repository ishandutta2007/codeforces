#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, x = 864197532, N = 100001, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
     * k = 2
     * 1 -> F
     * 2 -> F
     * 3 -> S
     * 4 -> F
     * 5 -> S
     * 6 -> F
     * 7 -> S
     * k = 3
     * 1 -> F
     * 2 -> S
     * 3 -> F
     * 4 -> S
     * k = 4
     * 1 -> F
     * 2 -> F
     * 3 -> S
     */
    /*
     * pile = 2
     * 3 5 -> 2 5 -> 2 4 || 1 5 || 1 1 5
     * k = 3
     * 6
     * 3
     * k = 2
     * 3 3
     */
    int n, k, tmp;
    cin >> n >> k;
    int xorr = 0;
    fop (i,0,n) {
        if (k & 1) {
            cin >> tmp;
            int t = tmp;
            int cnt = 0;
            while (tmp % 2 == 0) tmp >>= 1, cnt++;
            if (t == 1) xorr ^= 1;
            else if (t == 0 || t == 2 || ((t & 1) && t >= 5)) xorr ^= 0;
            else if ((cnt % 2 == 0 && tmp == 3) || (cnt % 2 == 1 && tmp != 3)) xorr ^= 1;
            else xorr ^= 2;
        } else {
            cin >> tmp;
            if (tmp <= 2) xorr ^= tmp;
            else xorr ^= (tmp & 1 ^ 1);
        }
    }
    cout << (xorr ? "Kevin\n" : "Nicky\n");
}