#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#endif

using namespace std;

typedef long long ll;
typedef long double ldb;

vector<vector<pair<int, int>>> g(32);

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int l, r;
    cin >> l >> r;
    int L = l;
    int R = r;
    int n = 32;
    cout << "YES" << endl;

    if (l == 1) {
        g[0].push_back({31, 1});
        l++;
    }
    if (l <= r) {
        g[0].push_back({1, l - 1});
        r -= (l - 1);
        l -= (l - 1);
        g[1].push_back({31, 1});
        for (int i = 0; i < 25; i++) {
            if ((r - 1) & (1 << i)) {
                g[1].push_back({i + 2, l});
                l += (1 << i);
            }
        }
        for (int i = 0; i < 25; i++) {
            g[i + 2].push_back({31, 1});
            for (int j = 0; j < i; j++) {
                g[i + 2].push_back({j + 2, 1 << j});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> ppp;
        for (auto pp : g[i]) {
            if (pp.second <= R) {
                ppp.push_back(pp);
            }
        }
        g[i] = ppp;
    }
    vector<int> mapp(32);
    iota(mapp.begin(), mapp.end(), 0);
    reverse(mapp.begin() + 2, mapp.end() - 1);
    int m = 0;
    for (int i = 0; i < n; i++)
        m += g[i].size();
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (auto j : g[i]) {
            cout << mapp[i] + 1 << " " << mapp[j.first] + 1 << " " << j.second << endl;
        }
    }
}