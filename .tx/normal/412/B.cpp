#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

#define sci(a) int a; scanf("%d", &a)
#define scii(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciii(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define scig(a) scanf("%d", &a)
#define sciig(a, b) scanf("%d%d", &a, &b)
#define sciiig(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef long long lint;

using namespace std;

int main() {
    scii(n, k);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scig(a[i]);
    }
    sort(a.rbegin(), a.rend());
    cout << a[k - 1];


    return 0;
}