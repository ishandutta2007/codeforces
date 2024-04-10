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
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 500500;
const int INF = 1e9;
int d[MAXN];
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    
    int n, a, b;
    cin >> n >> a >> b;

    int k = 3 * (max(a, b));
    // int k = n + 1;
    k /= a;
    ++k;
    k *= a;

    set<pii> setik;
    d[0] = 0;
    setik.insert({d[0], 0});
    for (int i = 1; i < k; ++i) {
        d[i] = INF;
        setik.insert({d[i], i});
    }

    for (int i = 0; i < k; ++i) {
        if (i + a < k) {
            g[i].push_back(i + a);
        }
        if (i - b >= 0) {
            g[i].push_back(i - b);
        }
    }

    while (!setik.empty()) {
        pii cur = *setik.begin();
        if (cur.first == INF) {
            break;
        }
        setik.erase(cur);

        int v = cur.second;

        for (int u : g[v]) {
            int dst = max(cur.first, u);
            if (dst < d[u]) {
                setik.erase({d[u], u});
                d[u] = dst;
                setik.insert({d[u], u});
            }
        }
    }

    ll res = 0;
    for (int i = 0; i < k; ++i) {
        // cout << i << ' ' << d[i] << endl;
        if (d[i] <= n) {
            res += n - d[i] + 1;
        }
    }

    if (k <= n) {
        for (int i = 0; i < a; ++i) {
            if (i % gcd(a, b) != 0) {
                continue;
            }
            if (k + i > n) {
                continue;
            }
            int t = n - k - i;
            ll u = t / a;
            res += u * (u + 1) / 2 * a + (u + 1) * (t % a + 1);
        }
    }

    cout << res << endl;
    
    
}