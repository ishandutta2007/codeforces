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

const int MAXN = 100100;
const int MAXM = 11;

int p[MAXM][MAXN];
int q[MAXM][MAXN];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
        }
        for (int j = 0; j < n; ++j) {
            q[i][p[i][j]] = j;
        }
    }

    ll res = 0, cur = 1;

    for (int i = 1; i < n; ++i) {
        int u = p[0][i - 1], v = p[0][i];
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            if (q[j][v] - q[j][u] != 1) {
                ok = false;
                break;
            }
        }   
        if (ok) {
            ++cur;
        } else {
            res += cur * (cur + 1) / 2;
            cur = 1;
        }
    }
    res += cur * (cur + 1) / 2;

    cout << res << endl;

}