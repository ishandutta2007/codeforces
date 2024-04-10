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

const int MAXN = 20000;

bool p[MAXN];
bool q[MAXN];

uint a, b, c, d;

uint f(uint x) {
    return ((a * x + b) * x + c) * x + d;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    uint n;
    cin >> n;
    cin >> a >> b >> c >> d;

    uint res = 0;

    for (uint i = 2; i < MAXN; ++i) {
        if (!p[i]) {
            for (uint j = i; i * j < MAXN; ++j) {
                p[i * j] = 1;
            }

            uint cnt = 0;
            uint cur = i;
            for (; cur <= n / i; cur *= i) {
                cnt += n / cur;
            }
            cnt += n / cur;
            res += cnt * f(i);
        }
    }

    for (uint k = 1; k * MAXN <= n; ++k) {
        uint l = k * MAXN;
        uint r = (k + 1) * MAXN - 1;
        memset(q, 0, sizeof(q));
        for (uint i = 2; i < MAXN; ++i) {
            if (p[i]) {
                continue;
            }
            for (uint j = (l - 1) / i + 1; j <= r / i; ++j) {
                q[i * j - l] = 1;
            }
        }

        for (uint i = 0; i < MAXN; ++i) {
            if (!q[i]) {
                uint x = i + l;
                res += f(x) * (n / x);
            }
        }
    }

    cout << res << endl;

    return 0;
}