#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char a[N], b[N];

vector<int> qa[26], qb[26];

void solv()
{
    memset(qa, 0, sizeof qa);
    memset(qb, 0, sizeof qb);
    scanf("%d", &n);
    scanf(" %s", a);
    scanf(" %s", b);
    for (int i = 0; i < n; ++i)
    {
        qa[a[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < n; ++i)
    {
        qb[b[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; ++i)
    {
        if (qa[i].size() != qb[i].size())
        {
            printf("NO\n");
            return;
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (qa[i].size() >= 2)
        {
            printf("YES\n");
            return;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (b[j] == a[i])
            {
                int x = j;
                for (int k = 0; k < j - i; ++k)
                {
                    swap(b[x], b[x - 1]);
                    ++ans;
                    --x;
                }
                break;
            }
        }
    }
    if (ans % 2 == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
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