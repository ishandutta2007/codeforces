#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &x[i], &y[i]);
    int ans = 0;
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
        int max_c = -1e9, min_c = 1e9;
        for (int k = 0; k < n; ++k) if (k != i && k != j) {
            int cross = (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
            if (cross < min_c) min_c = cross;
            if (cross > max_c) max_c = cross;
        }
        if (max_c - min_c > ans) ans = max_c - min_c;
    }
    printf("%.3lf", ans / 2.0);
}