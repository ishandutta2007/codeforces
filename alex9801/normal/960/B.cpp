#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

int a[1010];
int b[1010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, k1, k2, i;
    scanf("%d%d%d", &n, &k1, &k2);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    priority_queue<int> pq;
    for(i = 0; i < n; i++)
        pq.push(abs(a[i] - b[i]));

    for(i = 0; i < k1 + k2; i++)
    {
        int x = pq.top();
        pq.pop();

        if(x == 0)
            x++;
        else
            x--;

        pq.push(x);
    }

    long long res = 0;
    while(!pq.empty())
    {
        int x = pq.top();
        pq.pop();

        res += 1LL * x * x;
    }

    printf("%lld\n", res);
    return 0;
}