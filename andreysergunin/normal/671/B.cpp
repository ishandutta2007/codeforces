#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex>
#include <ctime>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()



int main() {
    long long n;
    long long k;

    cin >> n >> k;
    vector<long long> c(n);
    for (int i = 0; i < n; ++i)
        scanf("%I64d", &c[i]);
    long long sum = 0;
    sort(all(c));
    long long k1 = c[0];
    for (long long i = n - 1; i >= 0; --i) {
        long long j = i;
        while (j > 0 && c[j] == c[j - 1])
            --j;

        long long t = (j == 0 ? 0 : c[j - 1]);

        if (sum + (c[i] - t) * (n - j) <= k) {
            sum += (c[i] - t) * (n - j);
        }
        else {
            k1 = c[i] - ((k - sum) / (n - j));
            break;
        }
        i = j;
    }

    long long k2 = c[n - 1];

    sum = 0;

    for (long long i = 0; i < n; ++i) {
        long long j = i;
        while (j < n - 1 && c[j] == c[j + 1])
            ++j;

        if (j == n - 1)
            break;

        long long t = c[j + 1];

        if (sum + (t - c[i]) * (j + 1) <= k) {
            sum += (t - c[i]) * (j + 1);
        }
        else {
            k2 = c[i] + (k - sum) / (j + 1);
            break;
        }
        i = j;
    }

    sum = 0;

    for (int i = 0; i < n; ++i)
        sum += c[i];

    long long k3 = sum / n;

    long long ans;
    if (sum % n == 0)
        ans = max(k1, k3) - min(k2, k3);
    else
        ans = max(k1, k3 + 1) - min(k2, k3);


//   cout << k1 << " " << k2 << " " << k3 << endl;

    cout << ans << endl;
    return 0;
}