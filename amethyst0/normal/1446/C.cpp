#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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

const int maxn = (int)2e5 + 10;
const int maxm = maxn * 30;

int ed[maxm][2];
int posit = 0;

void add(int t, int x, int b) {
    if (b == -1) {
        return;
    }

    int c = (x >> b) & 1;

    if (ed[t][c] == -1) {
        ed[t][c] = posit++;
    }
    add(ed[t][c], x, b - 1);
}

int dp[maxm];

int go(int t) {
    if (ed[t][0] == -1 && ed[t][1] == -1) {
        return 1;
    }

    if (dp[t] != -1) {
        return dp[t];
    }

    dp[t] = go(ed[t][1]) + (ed[t][0] == -1 ? 0 : 1);
    dp[t] = max(dp[t], go(ed[t][0]) + (ed[t][1] == -1 ? 0 : 1));
    return dp[t];
}

int main() {
    memset(ed, -1, sizeof ed);
    int t = posit++;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        add(t, x, 29);
    }

    memset(dp, -1, sizeof dp);

    cout << n - go(t) << '\n';
}