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

pair<int, int> a[111111];
lint s[111111];
int aa[111111];

int main() {
    init_cin
    int n, A, CF, CM;
    lint m;
    cin >> n >> A >> CF >> CM >> m;
    int cA = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == A) {
            cA++;
        }
        a[i] = {x, i};
    }
    random_shuffle(a, a + n);
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        s[i] = a[i].first;
        if (i) {
            s[i] += s[i - 1];
        }
    }

    lint ans = 0;
    int ansA = -1;
    int ansM = -1;

    for (int i = cA; i <= n; i++) {
        int ta = i - cA;
        lint sa = s[n - 1];
        if (i < n) {
            sa -= s[n - i - 1];
        }
        lint ca = 1LL * i * A - sa;
        if (ca > m) {
            break;
        }

        if (i == n) {
            if (1LL * n * CF + 1LL * A * CM > ans) {
                ans = 1LL * n * CF + 1LL * A * CM;
                ansA = n;
                ansM = A;
            }
            break;
        }

        lint cm = m - ca;

        int l = 0, r = n - i;
        while (l + 1 < r) {
            int bm = (l + r) >> 1;
            lint sl = s[bm - 1];
            lint sn = 1LL * a[bm].first * bm;
            if (sn - sl <= cm) {
                l = bm;
            } else {
                r = bm;
            }
        }

        lint mn = a[l].first;
        if (l == 0) {
            mn = min(1LL * A, cm + a[l].first);
        } else {
            lint sl = s[l - 1];
            lint sn = 1LL * a[l].first * l;
            cm -= sn - sl;
            mn = min(1LL * A, a[l].first + cm / (l + 1));
        }

        if (1LL * i * CF + mn * CM > ans) {
            ans = 1LL * i * CF + mn * CM;
            ansA = i;
            ansM = mn;
        }
    }

    cout << ans << "\n";

    for (int i = 0; i < ansA; i++) {
        a[n - 1 - i].first = A;
    }

    for (int i = 0; i < n; i++) {
        a[i].first = max(a[i].first, ansM);
        aa[a[i].second] = a[i].first;
    }

    for (int i = 0; i < n; i++) {
        cout << aa[i] << " ";
    }


    return 0;
}