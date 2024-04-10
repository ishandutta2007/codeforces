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

int d[2222222];
char s[2222222];

int cnt[33];
int ls[33];

const int mod = 1e9 + 7;

int main() {
    sciid(n, k);
    scanf("\n%s", s);
    int m = strlen(s);
    for (int i = 0; i < m; i++) {
        cnt[s[i] - 'a']++;
    }
//    for (int i = 0; i < n; i++) {
//        int mn = 0;
//        for (int j = 1; j < k; j++) {
//            if (cnt[j] < cnt[mn]) {
//                mn = j;
//            }
//        }
//        s[i + m] = (char) (mn + 'a');
//        cnt[mn]++;
//    }
    d[0] = 1;
    memset(ls, -1, sizeof(ls));
    for (int i = 0; i < m; i++) {
        d[i + 1] = d[i] * 2 % mod;
        int c = s[i] - 'a';
        if (ls[c] != -1) {
            d[i + 1] = ((d[i + 1] - d[ls[c]]) % mod + mod) % mod;
        }
        ls[c] = i;
    }
    for (int i = m; i < m + n; i++) {
        int mn = 0;
        for (int j = 1; j < k; j++) {
            if (ls[j] < ls[mn]) {
                mn = j;
            }
        }
        d[i + 1] = d[i] * 2 % mod;
        int c = mn;
        if (ls[c] != -1) {
            d[i + 1] = ((d[i + 1] - d[ls[c]]) % mod + mod) % mod;
        }
        ls[c] = i;
    }
    cout << d[n + m];

    return 0;
}