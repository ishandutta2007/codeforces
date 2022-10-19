#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

#define M 100100
#define T 20

string s, t;
int a[M], b[M];

void read() {
    cin >> s >> t;
    for (int i = 0; i < (int) s.length(); ++i)
        a[i] = s[s.length() - 1 - i] - '0';
    for (int i = 0; i < (int) t.length(); ++i)
        b[i] = t[t.length() - 1 - i] - '0';
}

char kill() {
    int k = M - 1;
    while (k >= 2) {
        int t = min(a[k], b[k]);
        a[k] -= t;
        b[k] -= t;
        if (a[k] > T)
            return '>';
        if (b[k] > T)
            return '<';
        a[k - 1] += a[k];
        a[k - 2] += a[k];
        b[k - 1] += b[k];
        b[k - 2] += b[k];
        --k;
    }
    long double phi = (sqrt(5.0) + 1) * 0.5;
    long double A = a[0] + phi * a[1];
    long double B = b[0] + phi * b[1];
    long double eps = 1e-11;
    if (A + eps < B)
        return '<';
    if (A > B + eps)
        return '>';
    return '=';
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();

    cout << kill() << "\n";

    return 0;
}