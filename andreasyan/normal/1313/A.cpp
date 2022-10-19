#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

int q[3];

void solv()
{
    for (int i = 0; i < 3; ++i)
        scanf("%d", &q[i]);
    int ans = 1;
    for (int xx = 0; xx < (1 << (1 << 3)); ++xx)
    {
        int qq[3];
        for (int i = 0; i < 3; ++i)
            qq[i] = q[i];
        int yans = 0;
        bool z = true;
        for (int x = 0; x < (1 << 3); ++x)
        {
            if (!(xx & (1 << x)))
                continue;
            ++yans;
            for (int i = 0; i < 3; ++i)
            {
                if ((x & (1 << i)))
                {
                    if (!qq[i])
                    {
                        z = false;
                        break;
                    }
                    --qq[i];
                }
            }
            if (!z)
                break;
        }
        if (z)
        {
            ans = max(ans, yans);
        }
    }
    printf("%d\n", ans - 1);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}