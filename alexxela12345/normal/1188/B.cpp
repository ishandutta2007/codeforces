//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")
//#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define int ll
//#define double ld

signed main() {
    int n, p, k;
    cin >> n >> p >> k;
    map<int, int> cnt;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int y = x * x % p * x % p * x % p - k * x % p;
        y += p;
        y %= p;
        y += p;
        y %= p;
        ans += cnt[y];
        cnt[y]++;
    }
    cout << ans << endl;
}