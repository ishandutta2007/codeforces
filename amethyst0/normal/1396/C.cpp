#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)1e6 + 10;
ll dp[maxn][2];
int v[maxn];

int n;
ll r1, r2, r3;
ll d;

ll go(int pos, int fl) {
    if (dp[pos][fl] != -1) {
        return dp[pos][fl];
    }

    if (pos == n - 1) {
        if (!fl) {
            return dp[pos][fl] = min((ll)v[pos] * r1 + min(r3, 2 * r1 + 2 * d), r2 + 2ll * d + r1);
        }
        else {
            return dp[pos][fl] = min((ll)v[pos] * r1 + min(r3 + d + r1, r1 + d + r1 + d + r1), r2 + 2ll * d + r1 + r1);
        }
    }

    if (fl == 0) {
        return dp[pos][fl] = min((ll)v[pos] * r1 + min(r3 + go(pos + 1, 0), r1 + go(pos + 1, 1)), r2 + go(pos + 1, 1)) + d;
    }
    else {
        return dp[pos][fl] = min((ll)v[pos] * r1 + min(r3 + d + r1 + d + d + go(pos + 1, 0), r1 + d + r1 + d + r1 + d + go(pos + 1, 0)), r2 + d + r1 + d + r1 + d + go(pos + 1, 0));
    }
}

int main() {
    memset(dp, -1, sizeof dp);

    scanf("%d", &n);
    cin >> r1 >> r2 >> r3 >> d;

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    cout << go(0, 0) << '\n';
}