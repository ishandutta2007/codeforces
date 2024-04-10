#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int a[200000];

int main()
{
    int n, i, j = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > a[j])
            j = i;
    }
    if (a[j] != 1)
        a[j] = 1;
    else
        a[0] = 2;
    sort(a, a + n);
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}