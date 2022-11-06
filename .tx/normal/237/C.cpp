#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

bool notPrime[1111111];

int main() {
    sciiid(a, b, k);
    for (int i = 2; i <= b; i++) {
        if (!notPrime[i]) {
            for (int j = i + i; j <= b; j += i) {
                notPrime[j] = true;
            }
        }
    }
    notPrime[1] = true;
    int ans = -1;
    int cp = 0;
    int i;
    for (i = a; cp < k && i <= b; i++) {
        if (!notPrime[i]) {
            cp++;
        }
    }
    if (cp < k) {
        cout << -1;
        return 0;
    }
    ans = i - a;
    int last = a;
    while (i <= b) {
        while (i <= b && notPrime[i]) {
            i++;
        }
        if (i <= b) {
            cp++;
        } else {
            break;
        }
        while (cp > k) {
            if (!notPrime[last]) {
                cp--;
            }
            last++;
        }
        ans = max(ans, i - last + 1);
        i++;
    }
    while (notPrime[last]) {
        last++;
    }
    cout << max(ans, b - last + 1);

    return 0;
}