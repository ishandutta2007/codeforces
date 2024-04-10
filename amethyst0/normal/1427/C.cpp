#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast")
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

#define tm ajskdhaksjd

const int maxn = (int)2e5 + 10;
int tm[maxn], x[maxn], y[maxn];
int dp[maxn];
int res[maxn];

int main() {
    //freopen("input.txt", "r", stdin);
    
    int r, n;
    scanf("%d %d", &r, &n);
    tm[0] = 0;
    x[0] = 0;
    y[0] = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &tm[i], &x[i], &y[i]);
        x[i]--;
        y[i]--;

        if (abs(x[i]) + abs(y[i]) > tm[i]) {
            n--;
            i--;
            continue;
        }
    }

    dp[0] = 0;
    res[0] = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        res[i] = 1;

        for (int j = i - 1; j >= 0; j--) {
            if (tm[i] - tm[j] >= 2 * r) {
                res[i] = max(res[i], dp[j] + 1);
                break;
            }

            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= tm[i] - tm[j]) {
                res[i] = max(res[i], res[j] + 1);
            }
        }

        dp[i] = max(dp[i - 1], res[i]);
        ans = max(ans, res[i]);
    }

    cout << ans << '\n';
}