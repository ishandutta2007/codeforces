/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long  n;
    cin >> n;
    long long  ans = 0;
    for (long long  i = 0; i < n; i++) {
        long long  a, b, c;
        cin >> a >> b >> c;
        if (((a * x1 + b * y1 + c) < 0 && (a * x2 + b * y2 + c) > 0)
                || ((a * x1 + b * y1 + c) > 0 && (a * x2 + b * y2 + c) < 0))
            ans++;
    }
    cout << ans;
}