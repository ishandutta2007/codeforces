#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int ct;
    scanf("%d", &ct);

    for (int t = 0; t < ct; ++t)
    {
        int n;
        scanf("%d", &n);

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }

        int i = n - 1;
        while (i - 1 >= 0 && a[i - 1] <= a[i])
        {
            --i;
        }

        if (i < n - 1 && (a[i] - a[n - 1] <= a[i] || i == 0))
        {
            printf("%d\n", i);
            for (int j = 0; j < i; ++j)
                printf("%d %d %d\n", j + 1, i + 1, n);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}