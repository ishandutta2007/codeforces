#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 200 + 5;
const int MOD = 1e9 + 7;
const double eps8 = 1e-8;
const double eps9 = 1e-9;
const double pi = acos(-1);

struct pnt {
    double x, y;
    pnt() {}
    pnt(double x, double y): x(x), y(y) {}
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    double operator * (pnt A) {
        return x * A.y - y * A.x;
    }
    double operator % (pnt A) {
        return x * A.x + y * A.y;
    }
};


pnt p[200];
bool a[200][200];
long long dp[maxn][maxn];
int n;


bool boundBox(double a, double b, double c, double d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}

bool intersec(pnt A, pnt B, pnt C, pnt D) {
    return boundBox(A.x, B.x, C.x, D.x) && boundBox(A.y, B.y, C.y, D.y) && 
        ((C - A) * (B - A)) * ((D - A) * (B - A)) <= eps8 && 
        ((A - D) * (C - D)) * ((B - D) * (C - D)) <= eps8;
}
bool check(pnt A, pnt B, pnt C, pnt D) {
    pnt v, u, t;
    v = A - B;
    u = C - B;
    t = D - B;
    if ((v * u) * (v * t) < 0) {
        return v * u > 0;
    }
    if ((v * u) == 0) {
        return t * v > 0;
    }
    if ((v * t) == 0) {
        return v * u > 0;
    }
    return u * t > 0;
}


int main(){
    int v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    double ang = 0;
    for (int i = 0; i < n; i++) {
        pnt v, u;
        v = p[(i + 1) % n] - p[i];
        u = p[(i + 2) % n] - p[(i + 1) % n];
        ang += atan2(v * u, v % u);
    }
    if (ang < 0) {
        reverse(p, p + n);
    }
    for (int i = 0; i < n; i++)
       for (int j = i + 2; j < n; j++) {
           if (i == 0 && j == n - 1) continue;
           bool flag = 1;
           for (int k = 0; k < n; k++) {
                if (i == k || i == (k + 1) % n || j == k || j == (k + 1) % n) continue;
                flag &= !intersec(p[i], p[j], p[k], p[(k + 1) % n]);
           }
           flag &= check(p[(i - 1 + n) % n], p[i], p[(i + 1) % n], p[j]);
           flag &= check(p[(j - 1 + n) % n], p[j], p[(j + 1) % n], p[i]);
           a[i][j] = a[j][i] = flag;
       } 
    for (int i = 0; i < n; i++)
        a[i][(i + 1) % n] = a[(i + 1) % n][i] = 1;

    for (int i = 0; i < n; i++)
        dp[i][1] = 1;
    for (int i = 0; i < n; i++)
        if (a[i][(i + 2) % n])
            dp[i][2] = 1;
    for (int len = 3; len < n; len++) {
        for (int l = 0; l < n; l++) {
            int r = (l + len) % n;
            if (a[l][r] == 0) continue;
            for (int i = l + 1; i < l + len; i++) {
                v = i % n;
                if (a[l][v] == 0) continue; 
                dp[l][len] = (dp[l][len] + dp[l][i - l] * dp[v][l + len - i]) % MOD;
            }
        }
    }
    printf("%lld\n", dp[0][n - 1]);
    return 0;
}