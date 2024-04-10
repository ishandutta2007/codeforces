#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    double ans = 0;
    sort(p.begin(), p.end());
    if (p[n -  1] == 1) {
        ans = 1;
        cout << ans;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        double q = 1;
        double r = 0;
        for (int j = n - i; j < n; j++) {
            q *= (1 - p[j]);
            r += p[j] / (1 - p[j]);
        }
        q *= r;
        ans = max(ans, q);
    }
    printf("%.12lf", ans);
    return 0;
}