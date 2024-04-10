#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod = (int)998244353;
const int mod2 = (int)1e9 + 7;
int n;
ull dp[20][2530][(1<<8)];
bool u[20][2530][(1<<8)];
int good[2530][1<<8];
int A[1<<8][10];
ull l, r;
int a[25];
int L;
int M[23];
vector<int> d={2, 4, 8, 3, 9, 7, 5};
int add(int mask, int i) {
    return A[mask][i];
}

ull rec(int pos, int s, int mask) {
    if(pos == 0) {
        return good[s][mask];
    }
    ull &res = dp[pos][s][mask];
    if(u[pos][s][mask]) return res;
    res=0;
    u[pos][s][mask] = 1;
    for(int i = 0; i <= 9; i++) {
        res += rec(pos - 1, (s * 10 + i) % L, add(mask, i));
    }
    return res;
}
ull get(ull x) {
    n = 0;
    while(x > 0) {
        a[n++] = x % 10;
        x/=10;
    }
    reverse(a, a + n);
    ll ans = 0;
    int cur_mask = 0;
    int s = 0;
    for(int pos=0; pos < n; pos++) {
        for (int i = (pos == 0); i < a[pos]; i++)
            ans += rec(n - pos - 1, (s * 10 + i) % L, add(cur_mask, i));
        cur_mask = add(cur_mask, a[pos]);
        s = (s * 10 + a[pos]) % L;
    }
    ans += good[s][cur_mask];
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= 9; j++)
            ans += rec(i-1, j, add(0, j));
    }
    return ans;
}
void solve() {
    cin >> l >> r;
    ull ans = get(r);
    if(l > 1) ans -= get(l-1);
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    L=1;
    for(int i = 2; i <= 9; i++) {
        L = L * i/__gcd(L, i);
    }
    for(int i = 0; i < L; i++) {
        for(int mask = 0; mask < (1<<d.size()); mask++) {
            good[i][mask] = 1;
            for(int j = 0; j < d.size(); j++)
                if(mask & (1<<j)) {
                    if(i % d[j] != 0) good[i][mask] = 0;
                }
        }
    }
    for(int mask = 0; mask < (1<<d.size()); mask++) {
        int cur = 1;
        for(int j = 0; j < d.size(); j++) {
            if(mask & (1<<j)) cur = cur * d[j] / __gcd(cur, d[j]);
        }
        for(int i = 0; i <= 9; i++) {
            if(i == 0) {
                A[mask][i] = mask;
            } else {
                int cc = cur * i / __gcd(cur, i);
                int nmask = 0;
                for(int j = d.size() - 1; j >= 0; j--) {
                    if(cc % d[j] == 0) {
                        cc /= d[j];
                        nmask |= 1<<j;
                    }
                }
                A[mask][i] = nmask;
            }
        }
    }
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}