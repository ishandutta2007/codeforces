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


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, p;
    cin >> n >> p;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = r / p - (l - 1) / p;
        b[i] = r - l + 1;
    }
    double ans = (double)(b[0] * b[n - 1] - (b[0] - a[0])
                          * (b[n - 1] - a[n - 1])) / (double)(b[0] * b[n - 1]);
    for (int i = 0; i < n - 1; i++)
        ans += (double)(b[i] * b[i + 1] - (b[i] - a[i])
                        * (b[i + 1] - a[i + 1])) / (double)(b[i] * b[i + 1]);
    printf("%.9lf\n", ans * 2000);
    return 0;
}