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

int n, cnt, i;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);

    for (i = 1; i < n; i += 2)
        printf("%d ", i);
    if (n % 2 == 1) printf("%d ", n);
    for (i = (n % 2 == 1 ? n - 2 : n - 1); i > 0; i -= 2)
        printf("%d ", i);

    for (i = 2; i < n; i += 2)
        printf("%d ", i);
    if (n % 2 == 0) printf("%d ", n);
    for (i = (n % 2 == 0 ? n - 2 : n - 1); i > 0; i -= 2)
        printf("%d ", i);

    printf("%d", n);

    return 0;
}