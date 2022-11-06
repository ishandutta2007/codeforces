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

bool was[555][555];

int main() {
    init_cin;
    int x, y, x0, y0;
    cin >> x >> y >> x0 >> y0;
    --x0; --y0;
    string s;
    cin >> s;
    int k1 = 1;
    cout << 1;
    was[x0][y0] = true;
    for (int i = 0, len = s.length(); i + 1 < len; i++) {
        char c = s[i];
        int nx = x0, ny = y0;
        switch (c) {
            case 'U' :
                nx--;
                break;
            case 'D' :
                nx++;
                break;
            case 'L' :
                ny--;
                break;
            case 'R' :
                ny++;
                break;
        }
        if (nx < 0 || nx >= x || ny < 0 || ny >= y) {
            nx = x0;
            ny = y0;
        }
        if (!was[nx][ny]) {
            cout << " " << 1;
            was[nx][ny] = true;
            k1++;
        } else {
            cout << " " << 0;
        }
        x0 = nx;
        y0 = ny;
    }
    cout << " " << x * y - k1;

    return 0;
}