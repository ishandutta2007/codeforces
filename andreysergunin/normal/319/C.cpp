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

struct point {
    point() : x(0), y(0) {};
    point(long long x, long long y) : x(x), y(y) {};
    long long x;
    long long y;
};

point operator + (point a, point b) {
    return point(a.x + b.x, a.y + b.y);
}

point operator - (point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}

long long dotProduct(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

long long crossProduct(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

int f(point a, point b) {
    if ((double)a.x / a.y > (double)b.x / b.y)
        return 1;
    return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<long long> dp(n);
    dp[0] = 0;
    vector<point> hull(n);
    hull[0] = point(b[0], dp[0]);
    int k = 1;
    for (int i = 1; i < n; i++) {
        int l = 0, r = k;
        point q(a[i], 1);
        while (r - l > 2) {
            int m1 = (r + 2 * l) / 3;
            int m2 = (2 * r + l) / 3;
            long long u = dotProduct(q, hull[m1]);
            long long v = dotProduct(q, hull[m2]);
            if (u < v)
                r = m2;
            else
                l = m1;
        }
        if (l + 1 < r && dotProduct(q, hull[l]) > dotProduct(q, hull[l + 1]))
            l++;
        dp[i] = a[i] * hull[l].x + hull[l].y;
        point p(b[i], dp[i]);
        while (k > 1 && f(hull[k - 1] - hull[k - 2], p - hull[k - 1]) > 0)
            k--;
        hull[k++] = p;
    }
    cout << dp[n - 1] << endl;
}