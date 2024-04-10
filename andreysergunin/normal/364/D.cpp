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

using namespace std;

long long gcd(long long a, long long b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    long long ans = -1;
    random_shuffle(a.begin(), a.end());
    for (int t = 0; t < 100 && clock() <= 3 * CLOCKS_PER_SEC; t++) {
        int k = rand() % n;
        vector<long long> d;
        long long u;
        for (u = 1; u * u <= a[k]; u++)
            if (a[k] % u == 0)
                d.push_back(u);
        u--;
        if (u * u == a[k])
            u--;
        for (; u > 0; u--)
            if (a[k] % u == 0)
                d.push_back(a[k] / u);
        vector<int> c(d.size());
        for (int i = 0; i < n; i++) {
            long long x = gcd(a[k], a[i]);
            int ind = (int)(lower_bound(d.begin(), d.end(), x) - d.begin());
            c[ind]++;
        }
        for (int i = 0; i < (int)d.size(); i++) {
            int w = 0;
            for (int j = i; j < (int)d.size(); j++)
                if (d[j] % d[i] == 0)
                    w += c[j];
            if (w >= (n + 1) / 2 && d[i] > ans)
                ans = d[i];
        }
    }
    cout << ans << endl;
    return 0;
}