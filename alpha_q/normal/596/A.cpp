/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;

#define checkbit(n, b) ((n >> b) & 1)
#define gcd __gcd
#define bitcount __bultin_popcount
#define inf (int)1e9
#define eps 1e-9
#define pi acos(-1)
#define mod 100000007

struct point {
    int x, y;
    point (int _x, int _y) {x = _x; y = _y;}
    point () {}
    bool operator < (const point &p) const {
        if (y == p.y) return x < p.x;
        return y < p.y;
    }
};

point A[6]; int n, i, a, b;

int area (point A, point B) {
    return abs(B.x - A.x) * abs(B.y - A.y);
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &a, &b);
        A[i] = point(a, b);
    } sort (A + 1, A + n + 1);
    if (n == 1) printf("-1");
    else if (n >= 3) printf("%d", max(max(area(A[1], A[n]), area(A[2], A[3])), area(A[1], A[2])));
    else {
        if (A[1].x == A[2].x || A[1].y == A[2].y) printf("-1");
        else printf("%d", area(A[1], A[2]));
    }
    return 0;
}