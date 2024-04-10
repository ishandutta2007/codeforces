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

using namespace std;

vector<int> bad[44444];
int shift[44444];

int main() {
    sciid(n, m);
    sciid(k, t);
    for (int i = 0; i < k; i++) {
        sciid(x, y);
        --x; --y;
        bad[x].push_back(y);
    }
    for (int i = 1; i < n; i++) {
        shift[i] = (shift[i - 1] + m - bad[i - 1].size()) % 3;
    }

    string ans[3] = {"Carrots", "Kiwis", "Grapes"};

    while (t-- > 0) {
        sciid(x, y);
        --x; --y;
        bool yBad = false;
        int cntLess = 0;
        for (int i : bad[x]) {
            if (i == y) {
                yBad = true;
                break;
            }
            if (i < y) {
                cntLess++;
            }
        }
        if (yBad) {
            cout << "Waste\n";
            continue;
        }
        cout << ans[(y - cntLess + shift[x]) % 3] << "\n";
    }


    return 0;
}