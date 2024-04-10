#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;
const int V = 100100;
int a[V], _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        int m = 0;
        for (int i = 1; i * i <= n; ++i) {
            int x = n / i;
            int y = n / x;
            a[m++] = x;
            if (x != y) a[m++] = y;
        }
        a[m++] = 0;
        sort(a, a + m);
        printf("%d\n", m);
        for (int i = 0; i < m; ++i) printf("%d ", a[i]);puts("");
    }
    return 0;
}

/*
4
5
11
1
3
*/