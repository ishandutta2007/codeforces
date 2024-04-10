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

char a[3][3];
string b[2];

int main() {
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < 2; i++) {
            scanf("%s", a[i]);
        }
        b[t] = "";
        b[t] += a[0][0];
        b[t] += a[0][1];
        b[t] += a[1][1];
        b[t] += a[1][0];
        for (int i = 0; i < 4; i++) {
            if (b[t][i] == 'X') {
                b[t].erase(i, 1);
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (b[0] == b[1]) {
            cout << "YES";
            return 0;
        }
//        cerr << b[0];
        rotate(b[0].begin(), b[0].begin() + 1, b[0].end());
    }
    cout << "NO";

    return 0;
}