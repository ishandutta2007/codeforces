#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int maxn = 5e5 + 42;
const int mod = 1e9 + 7;

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

int inv(int x) {
    return bpow(x, mod - 2);
}

map<tuple<int, int, int>, int> prec;

int get(int r, int n, int k) {
    if(k == 1) {
        return inv(n + 1);
    } else if(prec.count(make_tuple(r, n, k))) {
        return prec[{r, n, k}];
    } else {
        int t = k / 2;
        int ans = 0;
        for(int i = r; i <= n; i++) {
            ans += get(i, n, t) * get(r, i, k - t);
            ans %= mod;
        }
        return prec[{r, n, k}] = ans;
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> divs;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            int cnt = 0;
            while(n % i == 0) {
                cnt++;
                n /= i;
            }
            divs.emplace_back(i, cnt);
        }
    }
    if(n != 1) {
        divs.emplace_back(n, 1);
    }
    int ans = 1;
    for(auto it: divs) {
        int cur = 0;
        for(int i = 0; i <= it.second; i++) {
            cur += bpow(it.first, i) * get(i, it.second, k);
            cur %= mod;
        }
        ans = ans * cur % mod;
    }
    cout << ans << endl;
    return 0;
}