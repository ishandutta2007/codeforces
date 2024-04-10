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
#include <queue>

#define fs first
#define sc second

using namespace std;

const int P = 1e9 + 7;

struct point {
    point (): x(0), y(0) {};
    point (double x, double y): x(x), y(y) {};
    double x;
    double y;
};

point operator - (point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}

bool operator == (point a, point b) {
    return (a.x == b.x && a.y == b.y);
}

vector<point> a;
int n;

double crossProduct(point a, point b) {
    return (a.x * b.y - a.y * b.x);
}

double dotProduct(point a, point b) {
    return (a.x * b.x + a.y * b.y);
}

bool inSeg (point a, point b, point c) {
    return (crossProduct(a - b, a - c) == 0 && dotProduct(a - b, a - c) >= 0 && dotProduct(b - a, b - c) >= 0);
}

bool inLine (point a, point b, point c) {
    return (crossProduct(a - b, a - c) == 0);
}

bool intSeg(point a, point b, point c, point d) {
    if (inSeg(a, b, c) || inSeg(a, b, d) || inSeg(c, d, a) || inSeg(c, d, b))
        return true;
    
    if (inLine(a, b, c) || inLine(a, b, d) || inLine(a, c, d) || inLine(b, c, d))
        return false;
    
    if (a == c || b == c || a == d || b == d)
        return false;
    
    if (crossProduct(a - b, a - c) > 0 &&  crossProduct(a - b, a - d) > 0)
        return false;
    if (crossProduct(a - b, a - c) < 0 &&  crossProduct(a - b, a - d) < 0)
        return false;
    
    if (crossProduct(c - d, c - a) > 0 &&  crossProduct(c - d, c - b) > 0)
        return false;
    if (crossProduct(c - d, c - a) < 0 &&  crossProduct(c - d, c - b) < 0)
        return false;
    return true;
}

bool pointInside(point b) {
    point c(b.x + 1e8 + 1, b.y + 1e8);
    int t = 0;
    for (int i = 0; i < n; i++)
        if (inSeg(a[i], a[(i + 1) % n], b))
            return true;
    for (int i = 0; i < n; i++) {
        if (intSeg(a[i], a[(i + 1) % n], b, c))
            t++;
    }
    if (t % 2 == 1)
        return true;
    return false;
}

bool diagInside(int i, int j) {
    point b((a[i].x + a[j].x) / 2, (a[i].y + a[j].y) / 2);
    if (!pointInside(b))
        return false;
    for (int k = 0; k < n; k++) {
        if (k == i || k == j)
            continue;
        if (inSeg(a[i], a[j], a[k]))
            return false;
    }
    for (int k = 0; k < n; k++) {
        if (k == i || k == j || (k + 1) % n == i || (k + 1) % n == j)
            continue;
        if (intSeg(a[k], a[(k + 1) % n], a[i], a[j]))
            return false;
    }
    return true;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    vector< vector<long long> > dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(n);
        if (i < n - 1)
            dp[i][i + 1] = 1;
    }
    for (int x = 2; x < n; x++) {
        for (int i = 0; i < n - x; i++) {
            dp[i][i + x] = 0;
            if (diagInside(i, i + x)) {
                for (int j = i + 1; j < i + x; j++) {
                    dp[i][i + x] = (dp[i][i + x] + dp[i][j] * dp[j][i + x]) % P;
                }
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}