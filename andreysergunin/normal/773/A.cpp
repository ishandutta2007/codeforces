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

const ll INF = 2e18;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll x, y;
        cin >> x >> y;
        ll p, q;
        cin >> p >> q;
        // cout << endl;
        // cout << x << " " << y << " " << p << " " << q << endl;

        if (p == q) {
            if (x == y) {
                cout << 0 << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }

        if (p == 0) {
            if (x == 0) {
                cout << 0 << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }

        ll u = (x > 0 ? (x - 1) / p + 1 : 0);
        ll v = (y != x ? (y - x - 1) / (q - p) + 1 : 0);
        ll w = (y - 1) / q + 1;
        // cout << u << " " << v << " " << w << endl;;
        ll ans = max({u, v, w}) * q - y;
        cout << ans << endl;
    }

    return 0;

}