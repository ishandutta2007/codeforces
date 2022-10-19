#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
int a[N];

bool c[N];
bool cc[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<int> ans;
    queue<int> q;
    int qq = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > 0)
        {
            int x = a[i];
            if (c[x] || cc[x])
            {
                printf("-1\n");
                return 0;
            }
            c[x] = true;
            ++qq;
            q.push(x);
        }
        else
        {
            int x = -a[i];
            if (!c[x] || cc[x])
            {
                printf("-1\n");
                return 0;
            }
            c[x] = false;
            --qq;
            cc[x] = true;
        }
        if (qq == 0)
        {
            ans.push_back(q.size() * 2);
            while (!q.empty())
            {
                cc[q.front()] = false;
                q.pop();
            }
        }
    }
    if (qq != 0)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}