#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n;
vector<int> a[N];

int main()
{
    scanf("%d", &n);
    for (int y = 2; y <= n; ++y)
    {
        int x;
        scanf("%d", &x);
        a[x].push_back(y);
    }
    for (int x = 1; x <= n; ++x)
    {
        if (a[x].empty())
            continue;
        int q = 0;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (a[h].empty())
                ++q;
        }
        if (q < 3)
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}