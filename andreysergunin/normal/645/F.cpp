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

const int P = 1e9 + 7;
const int MAXC = 1e6;

long long power(long long a, long long b) {
    if (b == 0)
        return 1;
    long long c = power(a, b / 2);
    c = (c * c) % P;
    if (b % 2 == 1)
        return (c * a) % P;
    return c;
}

int main() {
    long long n, k, q;
    cin >> n >> k >> q;
    vector<long long> a(MAXC + 1);
    vector<long long> phi(MAXC + 1);
    phi[1] = 1;
    for (int i = 2; i <= MAXC; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                int t = 1;
                int s = i;
                while (s % j == 0) {
                    t *= j;
                    s /= j;
                }
                phi[i] = phi[s] * (t - t / j);
                break;
            }
        }
        if (phi[i] == 0)
            phi[i] = i - 1;
    }
    vector<long long> c(n + q + 1);
    c[k - 1] = 1;
    for (long long i = k; i <= n + q; i++)
        c[i] = ((c[i - 1] * i) % P) * power(i - k + 1, P - 2) % P;
    long long ans = 0;
    for (int i = 0; i < n + q; i++) {
        long long fl;
        cin >> fl;
        vector<long long> d;
        d.push_back(1);
        for (int j = 2; j * j <= fl; j++) {
            if (fl % j == 0)
                d.push_back(j);
        }
        int m = (int)d.size() - 1;
        if (d[m] * d[m] == fl)
            --m;
        if (fl != 1)
            for (int j = m; j >= 0; j--)
                d.push_back(fl / d[j]);
        for (int j = 0; j < d.size(); j++) {
            ans += c[a[d[j]]] * phi[d[j]];
            ans %= P;
            ++a[d[j]];
        }
        if (i >= n)
            cout << ans << endl;
    }
    return 0;
}