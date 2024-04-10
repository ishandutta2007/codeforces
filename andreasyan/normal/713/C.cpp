#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 3003;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        a[i] -= i;
    }
    long long ans = 0;
    priority_queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (q.empty())
        {
            q.push(a[i]);
            continue;
        }
        if (q.top() < a[i])
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