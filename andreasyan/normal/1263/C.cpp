#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> ans;

void solv()
{
    scanf("%d", &n);
    ans.clear();
    ans.push_back(0);
    int i = n;
    while (1)
    {
        if (i == 0)
            break;
        ans.push_back((n / i));
        int l = 1, r = i;
        int u;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if ((n / m) == (n / i))
            {
                u = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        i = u - 1;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}