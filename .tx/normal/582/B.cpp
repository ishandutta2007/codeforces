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

int a[111111];
int d[111111];

int n, t;

void slow() {
    for (int i = n; i < t * n; i++) {
        a[i] = a[i - n];
    }
    int on = n;
    n = t * n;
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

//    for (int i = 0; i < n; i++) {
//        if (i > 0 && i % on == 0) {
//            cout << "\n";
//        }
//        printf("%3d ", d[i]);
//    }

    cout << (*max_element(d, d + n));
}

int main() {
    scii(n, t);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
//    cout << n << " " << 100 << " " << endl;
//    for (int i = 0; i < n; i++) {
//        printf("%3d ", a[i]);
//    }
//    cout << endl;
//    return 0; //
    int V = 51;
    if (t <= V) {
        slow();
        return 0;
    }
    for (int i = n; i < V * n; i++) {
        a[i] = a[i - n];
    }
    for (int j = 0; j < V * n; j++) {
        d[j] = 1;
        for (int i = 0; i < j; i++) {
            if (a[i] <= a[j]) {
                d[j] = max(d[j], d[i] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = (V - 1) * n; i < V * n; i++) {
        ans = max(ans, d[i] + (d[i] - d[i - n]) * (t - V));
    }
    cout << ans;
    return 0;
}