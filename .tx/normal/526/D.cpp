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

int main() {
    init_cin;
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> p(n);
    if (k == 1) {
        cout << 1;
    } else {
        cout << 0;
    }
    for (int i = 1; i < n; i++) {
        int x = p[i - 1];
        while (x > 0 && s[x] != s[i]) {
            x = p[x - 1];
        }
        if (s[i] == s[x]) {
            x++;
        }
        p[i] = x;
        lint s = i - x + 1;
        lint a = i - s * k + 1;
        lint b = s - a;
        if (b < 0) {
            lint t = (-b + s * (k + 1) - 1) / (s * (k + 1));
            b += t * s * (k + 1);
            a -= t * s * k;
        }
        if (a < 0) {
            cout << "0";
        } else {
            cout << "1";
        }
    }


    return 0;
}