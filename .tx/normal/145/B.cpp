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

string gen(string s, int c4, int c7, int c47, int c74, char last) {
    while (c47 > 0 || c74 > 0) {
        if (last == '4') {
            c47--;
            s += '7';
            c7--;
            last = '7';
        } else {
            c74--;
            s += '4';
            c4--;
            last = '4';
        }
    }
    if (c4 < 0 || c7 < 0 || c47 < 0 || c74 < 0) {
        return "";
    }
    string res = "";
    int i7 = -1;
    int i4 = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '7') {
            i7 = i;
        }
        if (i4 == -1 && s[i] == '4') {
            i4 = i;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        res += s[i];
        if (i == i4) {
            while (c4 > 0) {
                res += '4';
                c4--;
            }
        }
        if (i == i7) {
            while (c7 > 0) {
                res += '7';
                c7--;
            }
        }
    }

    if (c4 > 0 || c7 > 0) {
        return "";
    }
    return res;
}

int main() {
    sciid(a1, a2);
    sciid(a3, a4);
    if (abs(a3 - a4) > 1) {
        cout << -1;
        return 0;
    }

    if (a3 == 0 && a4 == 0 && a1 > 0 && a2 > 0) {
        cout << -1;
        return 0;
    }

    string s1 = gen("4", a1 - 1, a2, a3, a4, '4');
    string s2 = gen("7", a1, a2 - 1, a3, a4, '7');

    if (s1 == "" && s2 == "") {
        cout << -1;
    } else if (s1 == "") {
        cout << s2;
    } else if (s2 == "") {
        cout << s1;
    } else {
        cout << min(s1, s2);
    }

    return 0;
}