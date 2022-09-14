#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    vector<int> b(m + 1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] <= m)
            ++b[a[i]];
    }
    vector<int> c(m + 1);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j * i <= m; ++j)
            c[i * j] += b[i];
    int ans = 1;
    for (int i = 2; i <= m; ++i)
        if (c[ans] < c[i])
            ans = i;
    printf("%d %d\n", ans, c[ans]);
    for (int i = 0; i < n; ++i)
        if (ans % a[i] == 0)
            printf("%d ", i + 1);
    cout << endl;
    return 0;
}