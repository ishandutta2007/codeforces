#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

unordered_map<int, int> b;

int main() {
    string s;
    cin >> s;
    int mx = 0;
    int mxc = 1;
    int cb = 0;
    b[0] = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            cb++;
            if (b.find(cb) == b.end()) {
                b[cb] = i;
            }
        } else {
            b.erase(cb);
            cb--;
            if (b.find(cb) != b.end()) {
                int len = i - b[cb];
                if (len > mx) {
                    mx = len;
                    mxc = 0;
                }
                if (len == mx) {
                    mxc++;
                }
            } else {
                b[cb] = i;
            }
        }
    }
    cout << mx << " " << mxc;
    return 0;
}