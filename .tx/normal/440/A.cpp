#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef long long lint;

using namespace std;

int main() {
    scid(n);
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        sci(a[i]);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != i + 1) {
            cout << i + 1;
            return 0;
        }
    }
    cout << n;


    return 0;
}