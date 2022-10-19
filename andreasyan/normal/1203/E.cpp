#include <bits/stdc++.h>
using namespace std;
const int N = 150005;

int n;
int a[N];
bool c[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    for (int i = 1; i < N - 1; ++i)
    {
        if (i > 1 && a[i] >= 3)
        {
            c[i - 1] = c[i] = c[i + 1] = true;
        }
        if (i == 1 && a[i] >= 2)
        {
            c[i] = c[i + 1] = true;
        }
    }
    for (int i = 1; i < N - 1; ++i)
    {
        for (int j = max(1, i - 1); j <= i + 1; ++j)
        {
            if (!c[j] && a[i])
            {
                --a[i];
                c[j] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < N; ++i)
    {
        if (c[i])
            ++ans;
    }
    cout << ans << endl;
    return 0;
}