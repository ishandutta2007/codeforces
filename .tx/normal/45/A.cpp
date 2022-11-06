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

string ms[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main() {
    init_cin
    string s;
    cin >> s;
    int k;
    cin >> k;
    int cur = -1;
    for (int i = 0; i < 12; i++) {
        if (ms[i] == s) {
            cur = i;
            break;
        }
    }
    cur = (cur + k) % 12;
    cout << ms[cur];

    return 0;
}