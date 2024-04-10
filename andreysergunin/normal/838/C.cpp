#include <iostream>
#include <stdio.h>
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
 
// map<vector<int>, bool> mp;
 
// bool f(const vector<int> &a) {
//     int l = 0;
//     int x = 1;
//     for (int i = 1; i <= sz(a); ++i) {
//         if (i < sz(a) && a[i] == a[i - 1]) {
//             ++x;
//         } else {
//             x >>= 1;
//             for (; x > 0; x >>= 1)
//                 l -= x;
//             x = 1;
//         }        
//     }
//     int sum = sz(a);
//     sum >>= 1;
//     for (; sum > 0; sum >>= 1)
//         l += sum;
//     return l > 0;
// }
 
// bool solve(vector<int> a) {
//     if (mp.count(a))  {
//         return mp[a];
//     }
//     for (int i = 0; i < sz(a); ++i) {
//         if (i == sz(a) - 1 || a[i] != a[i + 1]) {
//             vector<int> c = a;
//             c.erase(c.begin() + i);
//             if (!solve(c)) {
//                 return mp[a] = 1;
//             }
//         }
//     }
//     return mp[a] = (f(a) > 0 ? 0 : 1);
// }
 
// void solve(int n, int lim, vector<int> &a) {
//     if (n == 0) {
//         solve(a);
//         return;
//     }
//     // for (int i = 0; i < sz(a); ++i)
//     //     cout << a[i] << " ";
//     // cout << "\n";
 
//     if (n >= lim) {
//         a.push_back(lim);
//         solve(n - 1, lim, a);
//         a.pop_back();
//     }
//     if (lim > 1) {
//         a.push_back(lim - 1);
//         solve(n - 1, lim - 1, a);
//         a.pop_back();
//     }
//     if (sz(a) == 0 && lim > 1) {
//         solve(n, lim - 1, a);
//     }
// }   
 
ll binPow(ll a, int b, int p) {
    if (b == 0)
        return 1;
    ll x = binPow(a, b / 2, p);
    x *= x;
    x %= p;
    if (b & 1) {
        x *= a;
        x %= p;
    }
    return x;
}

int n, k, p;
const int MAXN = 250250;
ll fact[MAXN], rfact[MAXN];
ll pw[MAXN];
int cnt = 0;
 
ll g[MAXN][17];

void solve(int n, const vector<int> &bit, int k, int l) {
    if (k == sz(bit)) {
        ++cnt;
        for (int i = 1; i < 17; ++i) {
            g[n][i] += rfact[l] * g[n ^ l][i - 1];
            if (cnt >= 8) {
                g[n][i] %= p;
            }
        }
        if (cnt >= 8)
            cnt = 0;
        return;
    }
    solve(n, bit, k + 1, l);
    solve(n, bit, k + 1, l ^ (1 << bit[k]));
}
  
int main() {
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    // int n;
    // cin >> n;
    // vector<int> a;
    // mp[a] = 0;
    // solve(n, n, a);
 
    // for (auto a : mp) {
    //     if (sz(a.first) < n)
    //         continue;
    //     cout << a.second << " ---> ";
    //     for (int i = 0; i < sz(a.first); ++i)
    //         cout << a.first[i] << " ";
    //     cout << "--- " << f(a.first);
    //     cout << "\n";
    // }
 
    cin >> n >> k >> p;
    if (n & 1) {
        cout << binPow(k, n, p) << "\n";
        return 0;
    }
 
    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % p;
        rfact[i] = binPow(fact[i], p - 2, p);
    }
 
    g[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        if ((i & n) != i)
            continue;
        vector<int> bit;
        for (int j = 0; j < 18; ++j) {
            if ((1 << j) & i)
                bit.push_back(j);
        }
        solve(i, bit, 1, 1 << bit[0]);
        for (int j = 0; j < 17; ++j)
            g[i][j] %= p;
    }
    ll ans = 0;
    for (int i = 1; i <= min(16, k); ++i) {
        g[n][i] %= p;
        ll cur = fact[n] * g[n][i];
        cur %= p;
        cur *= fact[k];
        cur %= p;
        cur *= rfact[k - i];
        cur %= p;
        ans += cur;
        ans %= p;
    }
    ans = binPow(k, n, p) - ans;
    if (ans < 0)
        ans += p;
    cout << ans << "\n";
    return 0;
}