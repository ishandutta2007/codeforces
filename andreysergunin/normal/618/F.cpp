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

const double PI = acos(-1);

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    vector<int> a[2];
    a[0].resize(n);
    a[1].resize(n);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    vector<long long> p[2];
    p[0].resize(n + 1);
    p[1].resize(n + 1);
    p[0][0] = 0;
    p[1][0] = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n; j++)
            p[i][j] = p[i][j - 1] + (long long) a[i][j - 1];
    int k = (p[0][n] <= p[1][n] ? 0 : 1);
    vector<int> u(n + 1);
    vector<int> v(n + 1);
    int m = 0;
    for (int i = 0; i <= n; i++) {
        while (p[1 - k][m] < p[k][i])
            m++;
        u[i] = (int)(p[1 - k][m] - p[k][i]);
        v[i] = m;
    }
    vector<int> d(n);
    for (int i = 0; i <= n; i++) {
        if (d[u[i]] != 0) {
            int x = i;
            int y = d[u[i]] - 1;
            if (k == 0) {
                printf("%d\n", x - y);
                for (int j = y + 1; j <= x; j++)
                    printf("%d ", j);
                printf("\n");
                printf("%d\n", v[x] - v[y]);
                for (int j = v[y] + 1; j <= v[x]; j++)
                    printf("%d ", j);
                printf("\n");
            }
            else {
                printf("%d\n", v[x] - v[y]);
                for (int j = v[y] + 1; j <= v[x]; j++)
                    printf("%d ", j);
                printf("\n");
                printf("%d\n", x - y);
                for (int j = y + 1; j <= x; j++)
                    printf("%d ", j);
                printf("\n");
            }
            return 0;
        }
        d[u[i]] = i + 1;
    }
    return 0;
}