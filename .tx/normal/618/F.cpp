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

lint a[1111111];
lint b[1111111];

int wa[1111111];
int wb[1111111];

int main() {
    scid(n);
    for (int i = 1; i <= n; i++) {
        scid(x);
        a[i] = a[i - 1] + x;
    }
    for (int i = 1; i <= n; i++) {
        scid(x);
        b[i] = b[i - 1] + x;
    }

    bool ws = false;
    if (a[n] > b[n]) {
        ws = true;
        for (int i = 1; i <= n; i++) {
            swap(a[i], b[i]);
        }
    }

    memset(wa, -1, sizeof(wa));
    wa[0] = 0;
    for (int i = 1; i <= n; i++) {
        int p = upper_bound(b + 1, b + n + 1, a[i]) - b - 1;
        int d = a[i] - b[p];
        if (wa[d] == -1) {
            wa[d] = i;
            wb[d] = p;
        } else {
            if (!ws) {
                cout << i - wa[d] << "\n";
                for (int t = wa[d] + 1; t <= i; t++) {
                    cout << t << " ";
                }
                cout << "\n";
                cout << p - wb[d] << "\n";
                for (int t = wb[d] + 1; t <= p; t++) {
                    cout << t << " ";
                }
            } else {
                cout << p - wb[d] << "\n";
                for (int t = wb[d] + 1; t <= p; t++) {
                    cout << t << " ";
                }
                cout << "\n";
                cout << i - wa[d] << "\n";
                for (int t = wa[d] + 1; t <= i; t++) {
                    cout << t << " ";
                }
            }
            return 0;
        }
    }

    return 0;
}