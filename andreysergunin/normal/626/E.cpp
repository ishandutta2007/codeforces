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

using namespace std;


int n;
vector<long long> p;
vector<long long> a;


double f(int k, long long m) {
    return (double)((p[n] - p[n - m]) + (p[k] - p[k - m]) - 2 * m * a[k]) / (double)(2 * m + 1);
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    p.resize(n + 1);
    p[0] = 0;
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];
    double cur = -1;
    long long x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        long long l = 0, r = min(i, n - 1 - i) + 1;
        while (r - l > 2) {
            long long m1 = (2 * l + r) / 3;
            long long m2 = (l + 2 * r) / 3;
            double a1 = f(i, m1);
            double a2 = f(i, m2);
            if (a1 > a2)
                r = m2;
            else
                l = m1;
        }
        if (l + 2 == r && f(i, l) < f(i, l + 1))
            l += 1;
        double a1 = f(i, l);
        if (cur < a1) {
            cur = a1;
            x = i;
            y = l;
        }
    }
    cout << 2 * y + 1 << endl;
    for (int i = 0; i <= y; i++)
        cout << a[x - y + i] << " ";
    for (int i = 0; i < y; i++)
        cout << a[n - y + i] << endl;
    return 0;
}