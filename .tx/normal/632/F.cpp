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

const int N = 2500;

int a[N][N];

bitset<N> b[N];

const string OK = "MAGIC";
const string FAIL = "NOT MAGIC";

pair<int, pair<int, int> > p[N * N];

int main() {
    scid(n);
    int mx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sci(a[i][j]);
            mx = max(mx, a[i][j]);
            p[i * n + j] = {a[i][j], {i, j}};
        }
    }

    sort(p, p + n * n);
    reverse(p, p + n * n);

    for (int i = 0; i < n; i++) {
        if (a[i][i] != 0) {
            cout << FAIL;
            return 0;
        }
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                cout << FAIL;
                return 0;
            }
        }
    }

    for (int i = 0; i < n * n;) {
        int j = i;
        for (; j < n * n && p[j].first == p[i].first; j++) {
            b[p[j].second.first].set(p[j].second.second);
        }
        for (int k = i; k < j; k++) {
            if ((b[p[k].second.first] | b[p[k].second.second]).count() != n) {
                cout << FAIL;
                return 0;
            }
        }
        i = j;
    }

    cout << OK;


    return 0;
}