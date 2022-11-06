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

pair<int, int> a[55];
int ps[55];
int ts[55];
int n, c;

int calc() {
    int x = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        x += a[i].second;
        res += max(0, a[i].first - x * c);
    }
    return res;
}

int main() {
    scii(n, c);
    rea(ps, n);
    rea(ts, n);
    for (int i = 0; i < n; i++) {
        a[i] = {ps[i], ts[i]};
    }

    int limak = calc();
    reverse(a, a + n);
    int radewoosh = calc();
    if (limak > radewoosh) {
        cout << "Limak";
    } else if (limak < radewoosh) {
        cout << "Radewoosh";
    } else {
        cout << "Tie";
    }

    return 0;
}