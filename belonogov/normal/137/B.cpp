#include <iostream>
#include <cstdio>

using namespace std;
int a[10000];

int main()
{
    int n, i, ans = 0, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &x);
        a[x-1]++;
    }
    for (i = 0; i < n; i++)
        if (! a[i])
            ans++;
    printf("%d", ans);
    return 0;
}