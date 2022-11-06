#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int arr[5010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);

    int nxt = 1;
    for(int i = 0; i < n; i++)
    {
        if(m == 0)
        {
            assert(1LL * INF - nxt * (n - i - 1) >= nxt);
            for(int j = i; j < n; j++)
                arr[j] = INF - nxt * (n - j - 1);

            break;
        }

        if(m >= i / 2)
        {
            arr[i] = nxt;
            nxt++;

            m -= i / 2;
            continue;
        }

        nxt = (nxt - 2 * m) + (nxt - 1);

        arr[i] = nxt;
        nxt++;

        m = 0;
    }

    if(m != 0)
        puts("-1");
    else
    {
        for(int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        puts("");
    }
    return 0;
}