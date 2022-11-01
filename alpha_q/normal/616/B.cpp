#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

const int inf = 100 + (int)1e9;

int n, m, temp, ret = 0, i, j, in;

int main () {
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        temp = inf;
        for (j = 0; j < m; j++) {
            scanf("%d", &in);
            temp = min(temp, in);
        }
        ret = max(ret, temp);
    }
    printf("%d\n", ret);
    return 0;
}