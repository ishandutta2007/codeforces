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

char toLow(char c) {
    if (c >= 'a' && c <= 'z') {
        return c;
    }
    return c - 'A' + 'a';
}

char toUp(char c) {
    c = toLow(c);
    return c - 'a' + 'A';
}

int main() {
    string s;
    cin >> s;
    int x;
    cin >> x;
    for (int i = 0; i < s.length(); i++) {
        if (toLow(s[i]) - 'a' < x) {
            s[i] = toUp(s[i]);
        } else {
            s[i] = toLow(s[i]);
        }
    }
    cout << s;

    return 0;
}