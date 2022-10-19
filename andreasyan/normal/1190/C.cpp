#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, k;
char a[N];

int p[N][2], s[N][2];

void solv()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", (a + 1));
    for (int i = 1; i <= n; ++i)
    {
        p[i][0] = p[i - 1][0];
        p[i][1] = p[i - 1][1];
        p[i][a[i] - '0'] = i;
    }
    for (int i = n; i >= 1; --i)
    {
        s[i][0] = s[i + 1][0];
        s[i][1] = s[i + 1][1];
        s[i][a[i] - '0'] = i;
    }
    if (!p[n][0] || !p[n][1])
    {
        printf("tokitsukaze\n");
        return;
    }
    if (p[n][0] - s[1][0] + 1 <= k)
    {
        printf("tokitsukaze\n");
        return;
    }
    if (p[n][1] - s[1][1] + 1 <= k)
    {
        printf("tokitsukaze\n");
        return;
    }
    for (int l = 1; l <= n - k + 1; ++l)
    {
        int r = l + k - 1;
        if (p[l - 1][1] && s[r + 1][1])
        {
            printf("once again\n");
            return;
        }
        else if (s[r + 1][1])
        {
            if (p[n][1] - s[r + 1][1] + 1 > k)
            {
                printf("once again\n");
                return;
            }
        }
        else if (p[l - 1][1])
        {
            if (p[l - 1][1] - s[1][1] + 1 > k)
            {
                printf("once again\n");
                return;
            }
        }
        if (p[l - 1][0] && s[r + 1][0])
        {
            printf("once again\n");
            return;
        }
        else if (s[r + 1][0])
        {
            if (p[n][0] - s[r + 1][0] + 1 > k)
            {
                printf("once again\n");
                return;
            }
        }
        else if (p[l - 1][0])
        {
            if (p[l - 1][0] - s[1][0] + 1 > k)
            {
                printf("once again\n");
                return;
            }
        }
    }
    printf("quailty\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}