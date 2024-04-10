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

int n, k, i, l, r;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);

    l = 1; r = n; k++;

    while (r - l + 1 > k)
        printf("%d ", l++);

    while (l <= r) {
        printf("%d ", l);
        if (l != r)
            printf("%d ", r);
        l++; r--;
    }

    return 0;
}