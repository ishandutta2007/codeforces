#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long

using namespace std;

typedef long long ll;

int n, k;
int a, b;

int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

int Abs(int x) {return x < 0 ? -x : x;}

void Do(int a, int b, int &x, int &y) {
    int det = Abs(a - b);
    int t = k / gcd(k, det);
    int s = det * t / k;
    for(int i = 0; i < n; i++) {
        int nw = t * i + s;
        int o = n / gcd(n, nw);
        x = min(x, o * t);
        y = max(y, o * t);
    }
}

signed main() {
    scanf("%lld%lld", &n, &k);
    scanf("%lld%lld", &a, &b);
    int x = 1e18, y = -1e18;
    Do(a, b, x, y);
    Do((k - a) % k, b, x, y);
    Do(a, (k - b) % k, x, y);
    Do((k - a) % k, (k - b) % k, x, y);
    printf("%lld %lld\n", x, y);
    return 0;
}