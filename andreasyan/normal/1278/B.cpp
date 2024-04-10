#include <bits/stdc++.h>
using namespace std;

void solv()
{
    int x, y;
    scanf("%d%d", &x, &y);
    x = abs(x - y);
    if (x == 0)
    {
        printf("0\n");
        return;
    }
    int s = 0;
    for (int i = 1; ; ++i)
    {
        s += i;
        if ((s % 2) == (x % 2) && x <= s)
        {
            printf("%d\n", i);
            return;
        }
    }
}

int main()
{
    /*for (int q = 0; q <= 15; ++q)
    {
        set<int> s;
        for (int x = 0; x < (1 << q); ++x)
        {
            int sum = 0;
            for (int i = 0; i < q; ++i)
            {
                if ((x & (1 << i)))
                    sum += (i + 1);
                else
                    sum -= (i + 1);
            }
            s.insert(abs(sum));
        }
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
            printf("%d ", *it);
        printf("\n");
    }
    return 0;*/
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}