#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
typedef long long ll;
const int N = 200005;

int q0, q1, k;

void solv()
{
    scanf("%d%d%d", &q0, &q1, &k);

    if (k == 0)
    {
        printf("Yes\n");
        for (int i = 0; i < q1; ++i)
            printf("1");
        for (int i = 0; i < q0; ++i)
            printf("0");
        printf("\n");
        for (int i = 0; i < q1; ++i)
            printf("1");
        for (int i = 0; i < q0; ++i)
            printf("0");
        printf("\n");
        return;
    }

    if (q0 == 0)
    {
        printf("No\n");
        return;
    }

    int aq0 = q0, aq1 = q1;
    int bq0 = q0, bq1 = q1;
    aq1--;
    bq1--;
    if (!(aq1 && bq0))
    {
        printf("No\n");
        return;
    }
    aq1--;
    bq0--;
    aq0--;
    bq1--;
    for (int i = 2; i < q0 + q1; ++i)
    {
        if ((i - 1) == k)
        {
            printf("Yes\n");
            printf("11");
            for (int j = 2; j < i; ++j)
            {
                if (aq1)
                {
                    --aq1;
                    printf("1");
                }
                else if (aq0)
                {
                    --aq0;
                    printf("0");
                }
                else
                    assert(false);
            }
            printf("0");
            for (int j = i + 1; j < q0 + q1; ++j)
            {
                if (aq1)
                {
                    --aq1;
                    printf("1");
                }
                else if (aq0)
                {
                    --aq0;
                    printf("0");
                }
                else
                    assert(false);
            }
            printf("\n");

            printf("10");
            for (int j = 2; j < i; ++j)
            {
                if (bq1)
                {
                    --bq1;
                    printf("1");
                }
                else if (bq0)
                {
                    --bq0;
                    printf("0");
                }
                else
                    assert(false);
            }
            printf("1");
            for (int j = i + 1; j < q0 + q1; ++j)
            {
                if (bq1)
                {
                    --bq1;
                    printf("1");
                }
                else if (bq0)
                {
                    --bq0;
                    printf("0");
                }
                else
                    assert(false);
            }
            printf("\n");
            return;
        }
    }

    printf("No\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}