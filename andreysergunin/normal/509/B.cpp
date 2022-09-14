#include <bits/stdc++.h>
#define sqr(a) ((a) * (a))

using namespace std;
const int MAXN = 11000;
const int INF = 1000000000;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    int a[200], b[200], c[200];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }


    sort(a, a + n);
    if (a[n - 1] - a[0] > k)
    {
        printf("NO\n");
        return 0;
    }
    for (int i = 0; i <= a[0]; i++)
        c[i] = 1;
    for (int i = a[0] + 1; i < a[n - 1]; i++)
        c[i] = i - a[0] + 1;
    printf("YES\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b[i]; j++)
            printf("%d ", c[j]);
        printf("\n");
    }

}