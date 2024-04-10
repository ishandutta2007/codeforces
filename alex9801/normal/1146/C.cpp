#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, i, j;
    scanf("%d", &n);

    int r = 0;
    for(i = 0; i < 9; i++)
    {
        vector<int> a, b;
        for(j = 1; j <= n; j++)
        {
            if(j & (1 << i))
                a.push_back(j);
            else
                b.push_back(j);
        }
        if(a.empty() || b.empty())
            continue;

        printf("%d %d", (int)a.size(), (int)b.size());
        for(int x : a)
            printf(" %d", x);
        for(int x : b)
            printf(" %d", x);
        puts("");
        fflush(stdout);

        int t;
        scanf("%d", &t);
        assert(t != -1);

        r = max(r, t);
    }

    printf("-1 %d\n", r);
    fflush(stdout);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, i;
    scanf("%d", &t);
    for(i = 0; i < t; i++)
        solve();
    return 0;
}