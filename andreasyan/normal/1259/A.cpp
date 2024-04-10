#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> vv;

void solv()
{
    scanf("%d", &n);
    for (int i = vv.size() - 1; i >= 0; --i)
    {
        if (vv[i] <= n)
        {
            printf("%d\n", i + 1);
            break;
        }
    }
}

int main()
{
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            int x = 0;
            for (int k = 0; k < i; ++k)
            {
                x *= 10;
                x += j;
            }
            vv.push_back(x);
        }
    }
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}