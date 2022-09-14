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
    vector<int> x(n + m), y(n + m), l(n + m);
    for (int i = 0; i < n + m; i++)
        cin >> x[i] >> y[i] >> l[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = n; j < n + m; j++) {
            if (x[j] <= x[i] && x[i] <= x[j] + l[j] && y[i] <= y[j] && y[j] <= y[i] + l[i]) {
                int a = min(x[i] - x[j], x[j] - x[i] + l[j]);
                int b = min(y[j] - y[i], y[i] - y[j] + l[i]);
                ans = max(ans, min(a, b));
            }
        }
    cout << ans;
}