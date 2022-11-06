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

bool isPrime(int x) {
    bool res = x != 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res = false;
            break;
        }
    }
    return res;
}

unsigned int d[111][1 << 17];
int p[111][1 << 17];
int masks[60];
pair<int, int> a[111];
int ans[111];

int main() {
    vector<int> primes;
    for (int i = 2; i <= 59; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    for (int i = 1; i <= 59; i++) {
        int& mask = masks[i];
        for (int j = 0; j < primes.size(); j++) {
            if (i % primes[j] == 0) {
                mask |= 1 << j;
            }
        }
    }
    memset(d, -1, sizeof(unsigned int) * 111 * (1 << 17));
//    memset(p, -1, sizeof(unsigned int) * 111 * (1 << 17));
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        a[i] = {x, i};
    }
    sort(a, a + n);
    int bd = max(0, n - 17);
    d[0][0] = 0;
    for (int i = 0; i < bd; i++) {
        d[i + 1][0] = a[i].first - 1 + d[i][0];
        p[i + 1][0] = 1;
    }
    for (int i = bd; i < n; i++) {
        for (int j = 0; j < (1 << 17); j++) {
            if (d[i][j] == -1) {
                continue;
            }
            for (int k = 1; k <= 59; k++) {
                if ((masks[k] & j) == 0) {
                    int nmask = masks[k] | j;
                    if (d[i + 1][nmask] > d[i][j] + abs(a[i].first - k)) {
                        d[i + 1][nmask] = d[i][j] + abs(a[i].first - k);
                        p[i + 1][nmask] = k;
                    }
                }
            }
        }
    }

    int x = -1;
    int mn = 1e9;
    for (int i = 0; i < (1 << 17); i++) {
        if (d[n][i] < mn) {
            mn = d[n][i];
            x = i;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        ans[a[i].second] = p[i + 1][x];
        x ^= masks[p[i + 1][x]];
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }


    return 0;
}