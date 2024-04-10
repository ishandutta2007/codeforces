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

int a[333333];
int tol[333333];
int tor[333333];

int main() {
    scid(n);
    rea(a, n);
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0) {
            if (a[j - 1] % a[i] == 0) {
                j = tol[j - 1];
            } else {
                break;
            }
        }
        tol[i] = j;
    }
    for (int i = n - 1; i >= 0; i--) {
        int j = i;
        while (j + 1 < n) {
            if (a[j + 1] % a[i] == 0) {
                j = tor[j + 1];
            } else {
                break;
            }
        }
        tor[i] = j;
    }

    int mx = 0;
    set<int> ans;
    for (int i = 0; i < n; i++) {
        int c = tor[i] - tol[i];
        if (c > mx) {
            mx = c;
            ans.clear();
        }
        if (c == mx) {
            ans.insert(tol[i]);
        }
    }
    cout << ans.size() << " " << mx << "\n";
    for (int i : ans) {
        cout << i + 1 << " ";
    }


    return 0;
}