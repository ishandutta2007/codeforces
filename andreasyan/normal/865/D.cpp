#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300005;

int n;

void solv()
{
    scanf("%d", &n);
    long long ans = 0;
    priority_queue<int> q;
    while (n--)
    {
        int x;
        scanf("%d", &x);
        q.push(-x);
        if (!q.empty() && q.top() + x > 0)
        {
            ans += q.top() + x;
            q.pop();
            q.push(-x);
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