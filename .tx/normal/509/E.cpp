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

char s[555555];
int a[555555];

bool vowel(char c) {
    return c == 'I' || c == 'E' || c == 'A' || c == 'O' || c == 'U' || c == 'Y';
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        a[i] = vowel(s[i]) ? 1 : 0;
        if (i) {
            a[i] += a[i - 1];
        }
    }

    double cm = 0;
    for (int i = 1; i <= n; i++) {
        cm += 1.0 / i;
    }

    double ans = 0;

    for (int i = 0; i <= n - 1 - i; i++) {
        ans += cm * (a[n - 1 - i] - (i == 0 ? 0 : a[i - 1]));
        cm -= 1.0 / (i + 1) + 1.0 / (n - i);
    }

    printf("%.11f", ans);


    return 0;
}