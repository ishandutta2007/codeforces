#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(int x, int y): x(x), y(y) {}

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
};

const int MAXN = 205, MOD = 1000 * 1000 * 1000 + 7;
Point p[MAXN];
int dp[MAXN][MAXN], n;

long long cp(const Point &a, const Point &b) {
    return (long long)a.x * b.y - (long long)a.y * b.x;
}

int getdp(int l, int r) {
    if(dp[l][r] != -1)
        return dp[l][r];
    dp[l][r] = 0;
    for(int i = l + 1; i + 1 <= r; i++)
        if(cp(p[r] - p[l], p[i] - p[l]) < 0)
            dp[l][r] = (dp[l][r] + (long long)getdp(l, i) * getdp(i, r)) % MOD;
    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    p[n] = p[0];
    long long s = 0;
    for(int i = 0; i < n; i++)
        s += cp(p[i], p[i + 1]);
    if(s < 0)
        reverse(p, p + n + 1);
    for(int i = 0; i + 1 < n; i++) {
        dp[i][i + 1] = 1;
        for(int j = i + 2; j < n; j++)
            dp[i][j] = -1;
    }
    cout << getdp(0, n - 1) << '\n';
    return 0;
}