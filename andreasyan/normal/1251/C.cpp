#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
char a[N];

char ans[N];
void solv()
{
    scanf(" %s", a);
    n = strlen(a);
    queue<char> q0, q1;
    for (int i = 0; i < n; ++i)
    {
        if ((a[i] - '0') % 2 == 0)
        {
            q0.push(a[i]);
        }
        else
        {
            q1.push(a[i]);
        }
    }
    ans[n] = 0;
    int i = 0;
    while (1)
    {
        if (q0.empty() && q1.empty())
        {
            printf("%s\n", ans);
            return;
        }
        if (q0.empty())
        {
            ans[i++] = q1.front();
            q1.pop();
            continue;
        }
        if (q1.empty())
        {
            ans[i++] = q0.front();
            q0.pop();
            continue;
        }
        if (q0.front() < q1.front())
        {
            ans[i++] = q0.front();
            q0.pop();
        }
        else
        {
            ans[i++] = q1.front();
            q1.pop();
        }
    }
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}