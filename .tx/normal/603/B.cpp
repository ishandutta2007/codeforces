#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

const int mod = (int) 1e9 + 7;
int k, p;

int pow(int a, int p) {
    lint res = 1;
    for (int i = 0; i < p; i++) {
        res = (res * a) % mod;
    }
    return (int) res;
}

bool used[1111111];

int dfs(int v) {
    used[v] = true;
    int to = 1LL * k * v % p;
    if (!used[to]) {
        return dfs(to) + 1;
    }
    return 1;
}

int main() {
    scii(p, k);

    if (k == 0) {
        cout << pow(p, p - 1);
        return 0;
    }

    if (k == 1) {
        cout << pow(p, p);
        return 0;
    }

    int x = 0;
    for (int i = 0; i < p; i++) {
        if (!used[i]) {
            int y = dfs(i);
            if (y != 1) {
                x++;
            }
        }
    }
    cout << pow(p, x);
    return 0;
}