#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int)1e9 + 7;

using namespace std;

int n;
int ans = 0;
int fact[2001000];
int inv[2001000];

int binpow(int a, int k) {
    int res = 1;
    while (k){
        if (k&1)    
            res = res *1ll* a % mod;
        a = a * 1ll * a %mod;
        k >>= 1;
    }
    return res;
}

int C(int n, int k) {
    if (k > n) {
        return 0;
    }
    int ans = fact[n];
    ans = 1ll * ans * inv[k] % mod;
    ans = 1ll * ans * inv[n - k] % mod;
    return ans;
}

int main () {

    fact[0] = inv[0] = 1;
    for (int i = 1; i < 2001000; i++) {
        fact[i] = 1ll * i * fact[i - 1] % mod;
        inv[i] = binpow(fact[i], mod - 2);
    }

    cin >> n;

    bool was = false;
    int prev = -1;
    for (int sz = 1; sz <= 2 * n; sz++) {
        if (sz <= n) {
            ans = (ans + binpow(2, sz));
            if (ans >= mod) {
                ans -= mod;
            }
        } else {
            if (sz == n + 1) {
                prev = 0;
                for (int i = sz - n; i <= n; i++) {
                    prev = (prev + C(sz, i));
                    if (prev >= mod) {
                        prev -= mod;
                    }
                }
                ans = (ans + prev);
                if (ans >= mod) {
                    ans -= mod;
                }
            } else {
                int cur = (2 * prev % mod - C(sz - 1, sz - 1 - n));
                if (cur < 0) {
                    cur += mod;
                }
                cur = (cur - C(sz - 1, n));
                if (cur < 0) {
                    cur += mod;
                }
                ans = (ans + cur);
                if (ans >= mod) {
                    ans -= mod;
                }
                prev = cur;
            }
        }
    }

    ans++;

    ans %= mod;

    cout << ans << endl;

    return 0;
}