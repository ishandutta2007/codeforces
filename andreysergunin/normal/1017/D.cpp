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

mt19937 rnd(random_device{}());

const int MAXC = 101;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> f(1 << n);
    vector<int> w(n);

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                f[mask] += w[i]; 
            }
        }
    }

    vector<int> cnt(1 << n);

    for (int i = 0; i < m; ++i) {
        int x = 0;
        string s;
        cin >> s;
        for (int i = n - 1; i >= 0; --i) {
            x *= 2;
            x += (s[i] - '0');
        }
        ++cnt[x];
    }

    vector<vector<int>> res(1 << n, vector<int>(MAXC));

    int full = (1 << n) - 1;

    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> p(MAXC);

        for (int mask1 = 0; mask1 < (1 << n); ++mask1) {
            if (f[full ^ mask1] < MAXC) {
                p[f[full ^ mask1]] += cnt[mask ^ mask1];
            }
        }

        int cur = 0;

        for (int i = 0; i < MAXC; ++i) {
            cur += p[i];
            res[mask][i] = cur;
        }
    }

    for (int i = 0; i < q; ++i) {
        int x = 0, k;
        string s;
        cin >> s >> k;
        for (int i = n - 1; i >= 0; --i) {
            x *= 2;
            x += (s[i] - '0');
        }

        cout << res[x][k] << endl;
    }

    return 0;
}