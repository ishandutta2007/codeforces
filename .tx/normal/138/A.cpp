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
typedef long double ldouble;

using namespace std;

string a[3333 * 4];

int n, k;

bool vow(char c) {
    return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
}

int sl(string& a) {
    int x = 0;
    for (int i = (int) a.length() - 1; i >= 0; i--) {
        if (vow(a[i])) {
            x++;
        }
        if (x == k) {
            return i;
        }
    }
    return -1;
}

bool rh(string& a, string& b) {
    int p1 = sl(a);
    int p2 = sl(b);
    if (p1 == -1 || p2 == -1 || (a.length() - p1) != (b.length() - p2)) {
        return false;
    }
    for (int i = 0; i + p1 < a.length(); i++) {
        if (a[i + p1] != b[i + p2]) {
            return false;
        }
    }
    return true;
}


int main() {
    init_cin
    cin >> n >> k;
    n *= 4;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool aaaa, abab, abba, aabb;
    aaaa = abab = abba = aabb = true;
    for (int i = 0; i < n; i += 4) {
        if (!rh(a[i], a[i + 1])) {
            aaaa = aabb = false;
        }
        if (!rh(a[i], a[i + 2])) {
            aaaa = abab = false;
        }
        if (!rh(a[i], a[i + 3])) {
            aaaa = abba = false;
        }
        if (!rh(a[i + 1], a[i + 2])) {
            aaaa = abba = false;
        }
        if (!rh(a[i + 1], a[i + 3])) {
            aaaa = abab = false;
        }
        if (!rh(a[i + 2], a[i + 3])) {
            aaaa = aabb = false;
        }
    }
    if (aaaa) {
        cout << "aaaa";
    } else if (abab) {
        cout << "abab";
    } else if (abba) {
        cout << "abba";
    } else if (aabb) {
        cout << "aabb";
    } else {
        cout << "NO";
    }

    return 0;
}