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

int cc = 0;
char nc() {
    char res = cc + 'a';
    cc = (cc + 1) % 26;
    return res;
}

char ans[4][111];

void solve_even(int f, int n) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j * 2 < n; j++) {
            ans[i][f + j * 2] = 'a' + (i ^ (j & 1));
            ans[i][f + j * 2 + 1] = 'a' + (i ^ (j & 1));
        }
    }
    ans[2][0] = ans[3][0] = 'y';
    ans[2][n - 1] = ans[3][n - 1] = 'z';
    for (int i = 2; i < 4; i++) {
        for (int j = 0; j * 2 < n - 2; j++) {
            ans[i][1 + j * 2] = 'a' + (i ^ (j & 1));
            ans[i][1 + j * 2 + 1] = 'a' + (i ^ (j & 1));
        }
    }
}

char s3[4][3] = {{'x', 'x', 'y'}, {'z', 'z', 'y'}, {'y', 'x', 'x'}, {'y', 'z', 'z'}};

void solve3() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            ans[i][j] = s3[i][j];
        }
    }
}

void solve_odd(int n) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j * 2 < n - 1; j++) {
            ans[i][j * 2] = ans[i][j * 2 + 1] = 'a' + (i ^ (j & 1));
        }
        ans[i][n - 1] = 'y';
    }
    for (int i = 2; i < 4; i++) {
        for (int j = 1; j * 2 < n; j++) {
            ans[i][j * 2 - 1] = ans[i][j * 2] = 'a' + (i ^ (j & 1));
        }
        ans[i][0] = 'y';
    }
}

int main() {
    scid(n);
    if (n == 1) {
        cout << "a\na\nb\nb";
        return 0;
    }
    if (n % 2 == 0) {
        solve_even(0, n);
    } else {
        solve_odd(n);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}