#include <iostream>

using namespace std;

long long getS(int x, int y, int n, int d) {
    long long res = ((long long)(2 * d + 1) * (2 * d + 1) + 1) / 2;
    if(x - d < 0) {
        long long l = y - (d - x) + 1, r = y + (d - x) - 1;
        res -= ((r - l + 2) * ((r - l) / 2 + 1)) / 2;
        if(l < 0)
            res += -l * (-l + 1) / 2;
        if(r > n)
            res += (r - n) * (r - n + 1) / 2;
    }
    if(x + d > n) {
        long long l = y - (x + d - n) + 1, r = y + (x + d - n) - 1;
        res -= ((r - l + 2) * ((r - l) / 2 + 1)) / 2;
        if(l < 0)
            res += -l * (-l + 1) / 2;
        if(r > n)
            res += (r - n) * (r - n + 1) / 2;
    }
    if(y - d < 0) {
        long long l = x - (d - y) + 1, r = x + (d - y) - 1;
        res -= ((r - l + 2) * ((r - l) / 2 + 1)) / 2;
    }
    if(y + d > n) {
        long long l = x - (y + d - n) + 1, r = x + (y + d - n) - 1;
        res -= ((r - l + 2) * ((r - l) / 2 + 1)) / 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, x, y, c;
    cin >> n >> x >> y >> c;
    n--;
    x--;
    y--;
    int l = -1, r = 2 * n;
    while(l < r - 1) {
        int m = (l + r) / 2;
        long long s = getS(x, y, n, m);
        if(s < c)
            l = m;
        else
            r = m;
    }
    cout << r << '\n';
    return 0;
}