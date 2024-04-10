#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)                  (a).begin(), (a).end()
#define sz(a)                   int((a).size())
#define FOR(i, a, b)    for (int i(a); i < b; ++i)
#define REP(i, n)               FOR(i, 0, n)
#define UN(v)                   sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)                memset(a, b, sizeof a)
#define pb                              push_back
#define X                               first
#define Y                               second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

bool lucky[10000];

int a[100500];
int n, m;

int f[200500];

void put(int i, int d) {
        d -= f[i += n];
        if (d) {
                for (; i; i /= 2) {
                        f[i] += d;
                }
        }
}

int sum(int i, int j) {
        int res = 0;
        for (i += n, j += n; i <= j; i = (i + 1) / 2, j = (j - 1) / 2) {
                if (i & 1) res += f[i];
                if (~j & 1) res += f[j];
        }
        return res;
}

int main() {
        lucky[0] = true;
        FOR (i, 1, 10000) {
                lucky[i] = (i % 10 == 4 || i % 10 == 7) && lucky[i / 10];
        }
        scanf("%d%d", &n, &m);
        REP (i, n) {
                scanf("%d", a + i);
                put(i, lucky[a[i]]);
        }
        for (; m --> 0; ) {
                char q[8];
                int x, y;
                scanf("%s%d%d", q, &x, &y);
                --x;
                --y;
                if (q[0] == 'c') {
                        printf("%d\n", sum(x, y));
                } else {
                        int d;
                        scanf("%d", &d);
                        for (; x <= y; ++x) {
                                put(x, lucky[a[x] += d]);
                        }
                }
        }
        return 0;
}