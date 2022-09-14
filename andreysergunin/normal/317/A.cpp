#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long x, y, m;
    cin >> x >> y >> m;
    if (x >= m || y >= m) {
        cout << 0;
        return 0;
    }
    if (m <= 0) {
        cout << -1;
        return 0;
    }
    long long ans = 0;
    if (x < y)
        swap(x, y);
    if (x <= 0) {
        cout << -1;
        return 0;
    }
    if (y < 0) {
        ans += (-y) / x + 1;
        y += ((-y) / x + 1) * x;
    }
    if (x < y)
        swap(x, y);
    while (x < m) {
        ans++;
        y = x + y;
        swap(x, y);
    }
    cout << ans;
    return 0;
}