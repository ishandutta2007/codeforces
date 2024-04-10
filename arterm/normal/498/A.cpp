#include <bits/stdc++.h>

using namespace std;

#define long long long

struct line {
    long a, b, c;
    long val(long x, long y) {
        return a * x + b * y + c;
    }
    void read() {
        cin >> a >> b >> c;
    }
};

int sign(long x) {
    if (x < 0)
        return -1;
    return 1;
}

int main() {
    long x1, x2, x3, x4;
    cin >> x1 >> x2 >> x3 >> x4;
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        line l;
        l.read();
        if (sign(l.val(x1, x2)) != sign(l.val(x3, x4)))
            ans++;
    }
    cout << ans << "\n";
    return 0;
}