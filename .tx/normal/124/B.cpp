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

string a[11];
int x[11];
int p[11];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        p[i] = i;
    }

    int ans = 1e9;

    do {
        for (int i = 0; i < n; i++) {
            x[i] = 0;
            for (int j = 0; j < k; j++) {
                x[i] = x[i] * 10 + a[i][p[j]] - '0';
            }
        }
        ans = min(ans, (*max_element(x, x + n)) - (*min_element(x, x + n)));
    } while (next_permutation(p, p + k));

    cout << ans;

    return 0;
}