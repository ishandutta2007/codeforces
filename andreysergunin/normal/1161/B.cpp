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
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

int n;

int dist(int u, int v) {
    int d = abs(u - v);
    if (2 * d > n) {
        return n - d;
    }
    return d;
}

ll lcm(ll a, ll b) {
    ll x = a * b;
    if (x == 0) {
        return a + b;
    }
    x /= __gcd(a, b);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int m;
    cin >> n >> m;

    vector<vector<int>> s(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (u > v) {
            swap(u, v);
        }

        int dst = v - u;

        if (2 * dst > n) {
            dst = n - dst;
            swap(u, v);
        }

        s[dst].push_back(u);

        if (dst * 2 == n) {
            s[dst].push_back(v);
        }
    }

    for (int i = 0; i <= n; ++i) {
        sort(all(s[i]));
    }

    vector<int> dv;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            dv.push_back(i);
        }
    }


    for (int d : dv) {

        bool f = true;
        for (int i = 0; i <= n; ++i) {
            if (sz(s[i]) == 0) {
                continue;
            }

            vector<int> u = s[i], v = s[i];

            for (int j = 0; j < sz(v); ++j) {
                v[j] = (v[j] + d) % n;
            }

            int pos = 0;
            for (int j = 0; j < sz(v); ++j) {
                if (v[j] < v[pos]) {
                    pos = j;
                }
            }

            for (int j = 0; j < sz(v); ++j) {
                if (u[j] != v[(pos + j) % sz(v)]) {
                    f = false;
                }
            }   
        }

        if (f) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

}