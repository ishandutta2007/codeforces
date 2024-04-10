#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
pair <int, int> a[100000];

int main()
{
    int n, i, ans, r;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n);
    ans = 0;
    r = a[0].second;
    for (i = 1; i < n; i++)
        if (a[i].second > r)
            r = a[i].second;
        else
            ans++;

    printf("%d", ans);
    return 0;
}