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
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 2020;

int a[MAXN], b[MAXN];
int pa[MAXN], pb[MAXN];

int c[MAXN * MAXN];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m, x;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pa[i + 1] = pa[i] + a[i];
    }

    for (int j = 0; j < m; ++j) {
        cin >> b[j];
        pb[j + 1] = pb[j] + b[j];
    }
    cin >> x;

    memset(c, -1, sizeof(c));

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            c[pb[j] - pb[i]] = max(c[pb[j] - pb[i]], j - i);
        }
    }

    for (int i = 1; i < MAXN * MAXN; ++i) {
        c[i] = max(c[i], c[i - 1]);
    }

    int res = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int u = min(x / (pa[j] - pa[i]), MAXN * MAXN - 1);
            if (c[u] == -1) {
                continue;
            }
            res = max(res, (j - i) * c[u]);
        }
    }

    cout << res << endl;

}