#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5003;

int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    priority_queue<int> q;
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (q.empty() || q.top() <= a[i])
        {
            q.push(a[i]);
        }
        else
        {
            ans += (q.top() - a[i]);
            q.pop();
            q.push(a[i]);
            q.push(a[i]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}