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

// const int MAXN = 200200;

// int f[MAXN];

// void update(int p, int x) {
//     for (int i = p; i < MAXN; i |= (i + 1))
//         f[i] = max(f[i], x);
// }

// int get(int p) {
//     int ans = 0;
//     for (int i = p; i >= 0; i = (i & (i + 1)) - 1)
//         ans = max(ans, f[i]);
//     return ans;
// }

// bool operator < (const obj &a, const obj &b) {
//     if (a.x != b.x)
//         return a.x < b.x;
//     if (a.y != b.y)
//         return a.y < b.y;
//     return a.p < b.p;
// }

int solve(vector<pair<int, int>> &a, int lim) {
    int n = sz(a);
    sort(all(a));
    // for (int i = 0; i < n; ++i) 
    //     cout << a[i].first << " " << a[i].second << endl;
    // cout << endl;

    int ans = 0;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) 
        pref[i + 1] = max(pref[i], a[i].second);

    for (int i = 1; i < n; ++i) {
        if (a[i].first + a[i - 1].first > lim)
            break;
        ans = max(ans, a[i].second + pref[i]);
    }

    int l = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (l >= i)
            break;
        for (; l < i && a[i].first + a[l].first <= lim; ++l);
        if (a[i].first + a[0].first <= lim)
            ans = max(ans, a[i].second + pref[l]);
    }
    // cout << ans << endl;
    return ans;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    


    int n;
    cin >> n;
    int c, d;
    cin >> c >> d;
    int optx = 0, opty = 0;
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; ++i) {
        int x, p;
        char t;
        cin >> x >> p >> t;
        if (t == 'C') {
            a.push_back({p, x});
            if (p <= c) {
                optx = max(optx, x);
            }
        } else {
            b.push_back({p, x});
            if (p <= d) {
                opty = max(opty, x);
            }
        }
    }
        
    int ans = 0;
    if (optx != 0 && opty != 0)
        ans = optx + opty;
    ans = max(ans, solve(a, c));
    ans = max(ans, solve(b, d));

    cout << ans << endl;
    // int n;
    // cin >> n;
    // int x, y;
    // cin >> x >> y;
    // int ans = 0;
    // vector<obj> a(n);
    // for (int i = 0; i < n; ++i)
    //     cin >> a[i].x >> a[i].y >> a[i].p;
    
    // sort(all(a));

    // for (int i = 0; i < n; ++i) {
    //     if (i > 0 && a[i].x + a[i - 1].x <= x) {
    //         int tmp = get(y - a[i].y);
    //         if (tmp) {
    //             ans = min(ans, tmp + a[i].p);
    //         }
    //     }
    //     update(a[i].y, a[i].p);
    // }

    // for (int i = 0; i < MAXN; ++i)
    //     f[i] = 0;

    // int l = 0;
    // for (int i = n - 1; i >= 0; --i) {
    //     while (l < n && a[l].x + a[i].x <= x) {
    //         update(a[l].y, a[l].p);
    //         ++l;
    //     }
    //     int tmp = get(y - a[i].y);
    //     if (tmp) {
    //         ans = min(ans, tmp + a[i].p);
    //     }
    // }

    // cout << ans << endl;


}