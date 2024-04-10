#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char a[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", a);
    int z = 0;
    vector<int> ans;
    int q = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] == '<')
        {
            for (int j = z + q; j > z; --j)
                ans.push_back(j);
            z += q;
            q = 1;
        }
        else
            ++q;
    }
    for (int j = z + q; j > z; --j)
        ans.push_back(j);
    z = n + 1;
    vector<int> ans1;
    q = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] == '>')
        {
            for (int j = z - q; j < z; ++j)
                ans1.push_back(j);
            z -= q;
            q = 1;
        }
        else
            ++q;
    }
    for (int j = z - q; j < z; ++j)
        ans1.push_back(j);
    for (int i = 0; i < n; ++i)
        printf("%d ", ans1[i]);
    printf("\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
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