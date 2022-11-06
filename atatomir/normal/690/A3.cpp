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

int t, ti;
int n, r, i, x;
int sum;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {
        scanf("%d%d", &n, &r);

        sum = 0;
        for (i = 1; i < n; i++)
            scanf("%d", &x), sum += x;

        sum %= n;
        sum = (n + r - sum) % n;
        if (sum == 0) sum = n;

        printf("%d\n", sum);
    }


    return 0;
}