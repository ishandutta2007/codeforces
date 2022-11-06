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

int af[333];
bool p[333];
bool hp[333];

int main() {
    init_cin
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j + 1 < s.size(); j++) {
            af[s[j]] = s[j + 1];
            hp[s[j + 1]] = true;
            p[s[j]] = true;
        }
        p[s.back()] = true;
    }

    for (int i = 0; i < 333; i++) {
        if (p[i] && !hp[i]) {
            char c = i;
            while (c) {
                cout << c;
                c = af[c];
            }
        }
    }


    return 0;
}