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

int main() {
    string s;
    cin >> s;
    bool wasAt = false;
    string res = "";
    res += s[0];
    for (int i = 1; i < s.length(); i++) {
        if (!wasAt && i + 2 < s.length() && s.substr(i, 2) == "at") {
            wasAt = true;
            res += "@";
            i++;
        } else if (i + 3 < s.length() && s.substr(i, 3) == "dot") {
            res += ".";
            i += 2;
        } else {
            res += s[i];
        }
    }
    cout << res;

    return 0;
}