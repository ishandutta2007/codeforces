#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

bool nprime[11111111];
int cntA[11111111];
int cntB[11111111];
int delA[11111111];
int delB[11111111];
int a[111111];
int b[111111];

int main() {
    vector<int> primes;
    for (int i = 2; i <= 1e7; i++) {
        if (!nprime[i]) {
            for (int j = i + i; j <= 1e7; j += i) {
                nprime[j] = true;
            }
            primes.push_back(i);
        }
    }

    sciid(n, m);
    rea(a, n);
    rea(b, m);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int t = 0; primes[t] * primes[t] <= x; t++) {
            while (x % primes[t] == 0) {
                x /= primes[t];
                cntA[primes[t]]++;
            }
        }
        if (x != 1) {
            cntA[x]++;
        }
    }
    for (int i = 0; i < m; i++) {
        int x = b[i];
        for (int t = 0; primes[t] * primes[t] <= x; t++) {
            while (x % primes[t] == 0) {
                x /= primes[t];
                cntB[primes[t]]++;
            }
        }
        if (x != 1) {
            cntB[x]++;
        }
    }

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int t = 0; primes[t] * primes[t] <= x; t++) {
            int p = primes[t];
            while (x % p == 0) {
                x /= p;
                if (min(cntA[p], cntB[p]) > delA[p]) {
                    a[i] /= p;
                    delA[p]++;
                }
            }
        }
        if (x != 1 && min(cntA[x], cntB[x]) > delA[x]) {
            delA[x]++;
            a[i] /= x;
        }
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++) {
        int x = b[i];
        for (int t = 0; primes[t] * primes[t] <= x; t++) {
            int p = primes[t];
            while (x % p == 0) {
                x /= p;
                if (min(cntA[p], cntB[p]) > delB[p]) {
                    b[i] /= p;
                    delB[p]++;
                }
            }
        }
        if (x != 1 && min(cntA[x], cntB[x]) > delB[x]) {
            delB[x]++;
            b[i] /= x;
        }
        cout << b[i] << " ";
    }


    return 0;
}