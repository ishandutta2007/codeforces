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
    int x;
    string s;
    getline(cin, s);
    x = atoi(s.c_str());
    getline(cin, s);
//    cerr << s << endl;
    int n = s.size();
    vector<int> lens;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!') {
            if (cur > x) {
                cout << "Impossible";
                return 0;
            }
            lens.push_back(cur + 1);
            i++;
            cur = 0;
        } else {
            cur++;
        }
    }

    int ans = 1;
    cur = -1;

    for (int i : lens) {
//        cerr << i << endl;
        if (cur + 1 + i > x) {
            ans++;
            cur = i;
        } else {
            cur = cur + 1 + i;
        }
    }

    cout << ans;

    return 0;
}