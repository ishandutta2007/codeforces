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

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector< vector<long long> > dpNext, dpPrev;
    
    dpPrev.resize(k + 1);
    for (int j = 0; j <= k; j++)
        dpPrev[j].resize(n + 1);
    dpNext.resize(k + 1);
    for (int j = 0; j <= k; j++)
        dpNext[j].resize(n + 1);
    
    dpPrev[0][0] = 1;
    dpPrev[0][1] = 1;
    for (long long i = 0; i < n - 1; i++) {
        for (long long j = 0; j <= k; j++)
            for (long long l = 0; l <= n; l++)
                dpNext[j][l] = 0;
        for (long long j = 0; j <= k; j++)
            for (long long l = 0; l <= n; l++) {
                long long x = j + l * (a[i + 1] - a[i]);
                if (x <= k) {
                    dpNext[x][l] = (dpNext[x][l] + dpPrev[j][l] * (l + 1)) % P;
                    if (l < n)
                        dpNext[x][l + 1] = (dpNext[x][l + 1] + dpPrev[j][l]) % P;
                    if (l >= 1)
                        dpNext[x][l - 1] = (dpNext[x][l - 1] + dpPrev[j][l] * l) % P;
                }
            }
        for (long long j = 0; j <= k; j++)
            for (long long l = 0; l <= n; l++)
                dpPrev[j][l] = dpNext[j][l];
    }
    long long ans = 0;
    for (int i = 0; i <= k; i++)
        ans = (ans + dpPrev[i][0]) % P;
    cout << ans << endl;
    
    return 0;
}