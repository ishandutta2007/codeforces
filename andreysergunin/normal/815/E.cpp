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

map<pair<ll, ll>, ll> mp;

ll f(ll a, ll b) {
    if (mp.count({a, b})) 
        return mp[{a, b}];

    if (b > a) {
        return mp[{a, b}] = 0;
    }
    if (b == a) {
        return mp[{a, b}] = 1;
    }
    
    return mp[{a, b}] = f(a / 2, b) + f((a - 1) / 2, b);
}

vector<ll> a, b;
set<ll> s;

ll g(ll a, ll b) {
    if (!s.count(a) || !s.count(b))
        return 0;
    return f(a, b);
}

ll h(ll a, ll b) {
    return g(a, 2 * b + 1) + g(a, 2 * b + 2);
}

ll solve(ll n, ll k) {
    // cout << n << " " << k << endl;
    assert(n >= k && k >= 1);
    if (k == 1) 
        return (n + 1) / 2;

    ll x = (n - 1) / 2;
    ll y = n / 2;

    int m = sz(b);

    int i;
    ll u = 0, v = 0;
    for (i = m - 1; 1 + u + v < k && i >= 0; --i) {
        u += h(x, b[i]);
        v += h(y, b[i]);
    }
    ++i;
    u -= h(x, b[i]);
    v -= h(y, b[i]);

    if (1 + u + v + h(x, b[i]) >= k) {
        return solve(x, k - v - 1);
    } else {
        u += h(x, b[i]);
        return 1 + x + solve(y, k - u - 1);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;

    a = {n - 2};

    s.insert(n - 2);

    for (int l = 0; l < sz(a); ++l) {
        ll x = a[l] / 2;
        if (!s.count(x)) {
            s.insert(x);
            a.push_back(x);
        }
        x = (a[l] - 1) / 2;
        if (!s.count(x)) {
            s.insert(x);
            a.push_back(x);
        } 
    }
    sort(all(a));

    for (int i = 0; i < sz(a); ++i)  {
        if (i == 0 || (a[i - 1] - 1) / 2 != (a[i] - 1) / 2)
            b.push_back((a[i] - 1) / 2);
    }

    if (k == 1) {
        cout << 1 << endl;
        return 0;   
    } 

    if (k == 2) {
        cout << n << endl;
        return 0;
    }

    cout << 1 + solve(n - 2, k - 2) << endl;

    // int m = sz(a);
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         solve(a[i], a[j]);
    //     }
    // }

    // for (int i = 0; i < sz(a); ++i)
    //     cout << a[i] << " ";
    // cout << endl;

    // int k;
    // cin >> k;
    // for (int i = 2; i <= k; ++i) {
    //     int n = i;
    //     vector<int> a(n);
    //     a[0] = 1;
    //     a[n - 1] = 2;
    //     for (int i = 3; i <= n; ++i) {
    //         int dist = -1;
    //         int m = 0;
    //         for (int j = 0; j < n; ++j) {
    //             if (a[j]) {
    //                 continue;
    //             }
    //             int l = 0, r = 0;
    //             for (; !a[j + l]; ++l);
    //             for (; !a[j - r]; ++r);
    //             if (min(l, r) > dist) {
    //                 dist = min(l, r);
    //                 m = j;
    //             }
    //         }
    //         a[m] = i;
    //     }
    //     for (int i = 0; i < n; ++i)
    //         cout << a[i] << " ";
    //     cout << endl;
    // }
}