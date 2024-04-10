#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000006;

int n;
int a[N];
int qq;

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &qq);
    while (qq--)
    {
        int x;
        scanf("%d", &x);
        a[x] *= (-1);
    }
    stack<int> s;
    for (int i = n; i >= 1; --i)
    {
        if (a[i] < 0)
        {
            s.push(-a[i]);
        }
        else
        {
            if (!s.empty() && s.top() == a[i])
            {
                s.pop();
            }
            else
            {
                a[i] *= (-1);
                s.push(-a[i]);
            }
        }
    }
    if (!s.empty())
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}