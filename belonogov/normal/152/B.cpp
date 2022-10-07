#include <iostream>
#include <cstdio>

using namespace std;
const long long inf = 1e10;
struct point{
    long long x, y;
};

point a[20000];
long long f (long long x, long long q, long long n){
    if (q > 0)
        return  (n - x) / q;
    if (q == 0)
        return  inf;
    return - (x - 1) / q;
}

int main()
{
    long long n, m, x, y, i, k;
    long long ans = 0, d1, d2, d;
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;
    for (i = 0; i < k; i++)
        cin >> a[i].x >> a[i].y;
    for (i = 0; i < k; i++){
        d1 = f(x, a[i].x, n);
        d2 = f(y, a[i].y, m);
        d = min(d1, d2);
        x += d * a[i].x;
        y += d * a[i].y;
        ans += d;
    }
    cout << ans;
    return 0;
}