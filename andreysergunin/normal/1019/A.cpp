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
typedef long double ld;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const ll INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> p(m);

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        p[x].push_back(y);
    }

    for (int i = 0; i < m; ++i) {
        sort(all(p[i]));
    }

    ll res = INF;

    for (int h = max(sz(p[0]), 1); h <= n; ++h) {
        vector<int> u;
        int need = h - sz(p[0]);

        ll cur = 0;

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < sz(p[i]) - h + 1; ++j) {
                cur += p[i][j];
                --need;
            }
            for (int j = max(0, sz(p[i]) - h + 1); j < sz(p[i]); ++j) {
                u.push_back(p[i][j]);
            }
        }

        sort(all(u));
        reverse(all(u));

        while (need > 0 && sz(u) > 0) {
            --need;
            cur += u.back();
            u.pop_back();
        }


        if (need <= 0) {
            res = min(res, cur);
        }


    }

    cout << res << endl;
    

    return 0;
}