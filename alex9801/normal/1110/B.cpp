#include <bits/stdc++.h>

using namespace std;

int arr[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, k, i;
    scanf("%d%d%d", &n, &m, &k);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    priority_queue<int> pq;
    for(i = 0; i < n - 1; i++)
        pq.push(arr[i + 1] - arr[i] - 1);

    int r = arr[n - 1] - arr[0] + 1;
    for(i = 0; !pq.empty() && i < k - 1; i++)
    {
        r -= pq.top();
        pq.pop();
    }

    printf("%d\n", r);
    return 0;
}