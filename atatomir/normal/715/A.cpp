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

ll n, k, i, j, v, need;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);

    v = 2;
    for (i = 1; i <= n; i++) {
        need = (i + 1) * (i + 1) * i;
        v /= i;

        for (j = 1; need * j * j < v; j++);
        need *= j * j;

        printf("%lld\n", need - v);
        v = sqrt(need / i) * i;
    }


    return 0;
}