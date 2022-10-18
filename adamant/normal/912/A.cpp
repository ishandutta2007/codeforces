#include <bits/stdc++.h>
 
using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int x, y, z;
    cin >> x >> y >> z;
    a -= 2 * x + y;
    b -= y + 3 * z;
    cout << max((int)0, -a) + max((int)0, -b) << endl;
    return 0;
}