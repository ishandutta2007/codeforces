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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);  

    int n;
    cin >> n;
    map<pair<ll, ll>, ll> mapa;
    set<ll> xx, yy;

    for (int i = 0; i < n; ++i) {
        ll w, h, c;
        cin >> w >> h >> c;
        mapa[{w, h}] = c;
        xx.insert(w);
        yy.insert(h);
    }

    if ((ll)sz(xx) * sz(yy) != n) {
        cout << 0 << endl;
        return 0;
    }

    int u = sz(xx), v = sz(yy);

    vector<vector<ll>> c(u, vector<ll>(v));

    int ii = 0, jj = 0;
    for (ll x : xx) {
        jj = 0;
        for (ll y : yy) {
            c[ii][jj] = mapa[{x, y}];
            if (c[ii][jj] == 0) {
                cout << 0 << endl;
                return 0;
            }
            ++jj;
        }
        ++ii;
    }


    vector<ll> p(u);

    for (int i = 0; i < u; ++i) {
        p[i] = c[i][0];
        for (int j = 0; j < v; ++j) {
            p[i] = gcd(p[i], c[i][j]);
        }
        for (int j = 0; j < v; ++j) {
            c[i][j] /= p[i];
        }
    }

    // cout << u << " " << v << endl;
    // for (int i = 0; i < u; ++i) {
    //     for (int j = 0; j < v; ++j) {
    //         cout << c[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < u; ++i) {
        if (c[0] != c[i]) {
            cout << 0 << endl;
            return 0;
        }
    }


    ll g = p[0];
    for (int i = 0; i < u; ++i) {
        g = gcd(g, p[i]);
    }

    int ans = 0;
    for (ll i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            ++ans;
            if (i * i != g) {
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}