#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

vector<int> a[222];

int main() {
    sciid(n, m);
    n *= 2;
    int ca = 0;
    for (int i = 1; i <= m; i++) {
        a[ca++].push_back(i);
        if (ca == n) {
            ca = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        while (!a[i].empty()) {
            cout << a[i].back() << " ";
            a[i].pop_back();
        }
    }

    return 0;
}