#include <bits/stdc++.h>
using namespace std;

int arr[100010];
long long que[300010];
int a[100010];
int b[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, q, i;
    scanf("%d%d", &n, &q);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < q; i++)
        scanf("%lld", &que[i]);

    deque<int> dq;
    for(i = 0; i < n; i++)
        dq.push_back(arr[i]);

    for(i = 0; i < n; i++)
    {
        a[i] = dq.front();
        dq.pop_front();
        b[i] = dq.front();
        dq.pop_front();

        if(a[i] > b[i])
        {
            dq.push_front(a[i]);
            dq.push_back(b[i]);
        }
        else
        {
            dq.push_front(b[i]);
            dq.push_back(a[i]);
        }
    }

    for(i = 0; i < q; i++)
    {
        long long t = que[i] - 1;

        if(t < n)
        {
            printf("%d %d\n", a[t], b[t]);
            continue;
        }

        t -= n;
        t %= (n - 1);

        printf("%d %d\n", dq[0], dq[t + 1]);
    }

    return 0;
}