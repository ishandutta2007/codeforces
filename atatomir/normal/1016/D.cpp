#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 111;

int n, m, i, j, s1, s2;
int a[maxN], b[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s1 ^= a[i];
    }
    for (i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        s2 ^= b[i];
    }

    if (s1 != s2) {
        printf("NO\n");
        return 0;
    } else {
        printf("YES\n");
    }

    s1 = 0;
    for (i = 1; i < n; i++) {
        for (j = 1; j < m; j++) printf("0 ");
        printf("%d\n", a[i]);
        s1 ^= a[i];
    }

    for (i = 1; i < m; i++) printf("%d ", b[i]);
    printf("%d\n", s1 ^ b[m]);


    return 0;
}