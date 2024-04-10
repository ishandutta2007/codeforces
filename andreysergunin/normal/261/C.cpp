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

long long f(int d, int s, long long n) {
    vector<int> b(d);
    for (int i = 0; i < d; i++) {
        b[i] = n % 2;
        n /= 2;
    }
    vector< vector<long long> > a(d + 1);
    a[0].resize(d + 1);
    a[0][0] = 1;
    for (int i = 1; i <= d; i++) {
        a[i].resize(d + 1);
        a[i][0] = 1;
        for (int j = 1; j <= d; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }
    long long ans = 0;
    int k = s;
    for (int i = d - 1; i >= 0; i--) {
        if (b[i] == 1 && k >= 0) {
            ans += a[i][k];
            --k;
        }
    }
    if (k == 0)
        ans += 1;
    return ans;
}

int main() {
    long long n, t;
    cin >> n >> t;
    int k = 0;
    for (k = 0; t % 2 == 0; k++, t/= 2);
    if (t != 1) {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 0;
    for (long long l = 1; n > 0; l++) {
        long long m = (long long)1 << l;
        if (l < k) {
            n -= m;
            continue;
        }
        if (n > m)
            ans += f(l, k, m - 1);
        else
            ans += f(l, k, n - 1);
        n -= m;
    }
    cout << ans << endl;
    return 0;
}