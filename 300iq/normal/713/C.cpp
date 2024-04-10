#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    int n, x;
    priority_queue <int> q;
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        x -= i;
        if (q.empty() || q.top() <= x)
        {
            q.push(x);
        }
        else
        {
            q.push(x);
            q.push(x);
            ans += q.top() - x;
            q.pop();
        }
    }
    printf("%lld\n", ans);
}