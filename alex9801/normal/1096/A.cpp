#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, i;
    scanf("%d", &t);
    for(i = 0; i < t; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d %d\n", l, 2 * l);
    }
    return 0;
}