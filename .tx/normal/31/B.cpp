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
    init_cin
    string s;
    cin >> s;
    if (s[0] == '@' || s.back() == '@') {
        cout << "No solution";
        return 0;
    }
    vector<int> pa;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '@') {
            if (!pa.empty() && i - pa.back() < 3) {
                cout << "No solution";
                return 0;
            }
            pa.push_back(i);
        }
    }
    if (pa.empty()) {
        cout << "No solution";
        return 0;
    }
    bool w1 = false;
    for (int i = 0; i < s.length(); i++) {
        cout << s[i];
        if (s[i] == '@') {
            w1 = true;
        }
        if (w1 && i + 2 < s.length() && s[i + 2] == '@') {
            cout << ",";
        }
    }

    return 0;
}