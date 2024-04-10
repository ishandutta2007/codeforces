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

int main() {
    init_cin
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i + 1 < n && k > 0; i++) {
        if (s[i] == '4' && s[i + 1] == '7') {
            if (i & 1) {
                if (i > 0 && s[i - 1] == '4') {
                    k = min(k, k % 2 + 2);
                }
                s[i] = '7';
            } else {
                s[i + 1] = '4';
            }
            k--;
            i = max(-1, i - 2);
        }
    }
    cout << s;
    return 0;
}