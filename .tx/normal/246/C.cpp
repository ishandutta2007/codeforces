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

int a[55];

int popCount(lint x) {
    int res = 0;
    while (x) {
        res++;
        x &= x - 1;
    }
    return res;
}

int main() {
    sciid(n, k);
    for (int i = 0; i < n; ++i) {
        sci(a[i]);
    }
    sort(a, a + n);
    vector<lint> ans;
    for (int i = 0; i < n; i++) {
        lint suf = ((1LL << i) - 1) << (n - i);
        for (int j = 0; j + i < n; j++) {
            ans.push_back((1LL << j) | suf);
        }
    }
    for (int i = 0; i < k; i++) {
        lint t = ans[i];
        printf("%d", popCount(t));
        for (int j = 0; j < n; j++) {
            if (t & (1LL << j)) {
                printf(" %d", a[j]);
            }
        }
        printf("\n");
    }

    return 0;
}