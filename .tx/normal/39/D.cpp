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

vector<int> go(int x, int y, int z) {
    vector<int> res;
    if (x == 0) {
        res.push_back(0);
    } else {
        res.push_back(2);
    }
    if (y == 0) {
        res.push_back(3);
    } else {
        res.push_back(1);
    }
    if (z == 0) {
        res.push_back(4);
    } else {
        res.push_back(5);
    }
}

int main() {
    int x[3];
    int y[3];
    rea(x, 3);
    rea(y, 3);
    for (int i = 0; i < 3; i++) {
        if (x[i] == y[i]) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}