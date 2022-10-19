#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char a[N];
bool c[N];

vector<int> ans;

void solv()
{
    ans.clear();
    scanf(" %s", a);
    n = strlen(a);
    for (int i = 0; i < n; ++i)
        c[i] = false;
    for (int i = 0; i <= n - 5; ++i)
    {
        string s;
        for (int j = i; j < i + 5; ++j)
            s += a[j];
        if (s == "twone")
        {
            c[i + 2] = true;
            ans.push_back(i + 2);
        }
    }
    for (int i = 0; i <= n - 3; ++i)
    {
        bool z = false;
        string s;
        for (int j = i; j < i + 3; ++j)
        {
            s += a[j];
            if (c[j])
            {
                z = true;
                break;
            }
        }
        if (z)
            continue;
        if (s == "one" || s == "two")
        {
            c[i + 1] = true;
            ans.push_back(i + 1);
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i] + 1);
    printf("\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}