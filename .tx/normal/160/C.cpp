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

int main() {
    init_cin
    int n;
    lint k;
    cin >> n >> k;
    k--;
    unordered_map<int, int> cnt;
    cnt.reserve(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
        a[i] = x;
    }
    sort(a, a + n);
    for (int j = 0; j < n; j++) {
        if (j > 0 && a[j] == a[j - 1]) {
            continue;
        }
        auto i = *cnt.find(a[j]);
        if (1LL * i.second * n > k) {
            cout << i.first << " " << a[k / i.second];
            return 0;
        } else {
            k -= 1LL * i.second * n;
        }
    }

    return 0;
}