#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());


vector<int> phi;

ll binPow(ll a, ll b, ll m) {
    if (b == 0)
        return 1;
    ll x = binPow(a, b / 2, m);
    x *= x;
    x %= m;
    if (b & 1) {
        x *= a;
        x %= m;
    }
    return x;
}

ll f(ll a, ll b, ll m) {
    // cout << a << " " << b << " ";
    int x = __gcd(a, m);
    int y = __gcd(b, m);
    ll ans = 1;
    a /= x;
    b /= y;
    m /= y;
    ans *= b;
    ans *= binPow(a, phi[m] - 1, m);
    // cout << a << " " << b << " " << phi[m] << " " << binPow(a, phi[m] - 1, m) << endl;
    ans %= m;
    // cout << ans << endl;
    return ans * (y / x);
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m, 1);
    vector<vector<int>> v(m + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = 0;         
    }

    for (int i = 0; i < m; ++i) {
        if (a[i]) {
            v[__gcd(i + m, m)].push_back(i);
        }
    }

    vector<int> d;
    for (int i = 1; i <= m; ++i) {
        if (m % i == 0)
            d.push_back(i);
    }


    vector<int> dp(m + 1, 0);
    for (int i = m; i >= 1; --i) {
        if (m % i == 0) {
            for (int j = 1; j < sz(d); ++j) {
                if ((m / i) % d[j] == 0)
                    dp[i] = max(dp[i], dp[d[j] * i]);
            }
            dp[i] += sz(v[i]);
        }
    }

    vector<int> pr(m + 1);
    for (int i = 2; i <= m; ++i) {
        if (pr[i] == 0) {
            for (int j = 1; i * j <= m; ++j) {
                if (!pr[i * j])
                    pr[i * j] = i;
            }
        }
    }


    phi.resize(m + 1);
    phi[1] = 1;
    for (int i = 2; i <= m; ++i) {
        int tmp = i;
        int x = 1;
        while (tmp % pr[i] == 0) {
            x *= pr[i];
            tmp /= pr[i];
        }
        phi[i] = phi[tmp] * (x - x / pr[i]);
    }

    int cur = 1;
    ll prev = 1;

    cout << dp[1] << endl;

    for (; ; ) {
        for (int i = 0; i < sz(v[cur]); ++i) {
            int nxt = f(prev, v[cur][i], m);
            // cout << prev << " " << v[cur][i] << " " << nxt << endl;
            prev *= nxt;
            prev %= m;
            cout << nxt << " ";
        }

        if (cur == m)
            break;

        for (int i = 1; i < sz(d); ++i) {
            if ((m / cur) % d[i] == 0) {
                if (dp[cur] == dp[cur * d[i]] + sz(v[cur])) {
                    cur *= d[i];
                    break;
                }
            }
        }
    }
    cout << endl;


}