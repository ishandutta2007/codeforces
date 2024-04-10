#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e6 + 5;
int a[maxn], mod = 1e9 + 7, inf = 1e9;

int st(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        int c = st(a, b / 2);
        return c * c % mod;
    }
    return a * st(a, b - 1) % mod;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, p, ans = 0;
        cin >> n >> p;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = n; i >= 1; --i) {
            int j = i - 1, f = a[i], t = 1;
            while (j >= 1) {
                if (a[j] == f) {
                    t--;
                }
                else {
                    //t = t * st(p, f - a[j]);
                    if (p != 1) {
                        for (int s = 1; s <= f - a[j] && t < inf; ++s) {
                            t *= p;
                        }
                    }
                    f = a[j];
                    t--;
                }
                if (t == 0) break;
                j--;
                if (t > inf) {
                    j = 0;
                    break;
                }
            }
            if (j == 0) {
                ans = st(p, a[i]);
                for (int pos = 1; pos < i; ++pos) {
                    ans = (ans - st(p, a[pos]) + mod) % mod;
                }
            }
            i = j;
        }
        cout << ans << '\n';
    }
    return 0;
}