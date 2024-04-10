#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), h(n);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x - 1] = 1;
        h[y - 1] = 1;
    }
    int ans = 2 * n - 4;
    for (int i = 1; i < n - 1; i++)
        ans -= v[i] + h[i];
    if (n % 2 == 1 && v[n / 2] == 0 && h[n / 2] == 0)
        ans--;
    cout << ans;
    return 0;
}