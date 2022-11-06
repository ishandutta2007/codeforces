#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

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

int main() {
    int a[5];
    rea(a, 5);
    map<string, int> p;
    p["S"] = 0;
    p["M"] = 1;
    p["L"] = 2;
    p["XL"] = 3;
    p["XXL"] = 4;
    scid(n);
    string bans[5] = {"S", "M", "L", "XL", "XXL"};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = p[s];
        for (int j = 0; j < 5; j++) {
            if (x + j < 5 && a[x + j] != 0) {
                cout << bans[x + j] << "\n";
                a[x + j]--;
                break;
            }
            if (x - j >= 0 && a[x - j] != 0) {
                cout << bans[x - j] << "\n";
                a[x - j]--;
                break;
            }
        }
    }

    return 0;
}