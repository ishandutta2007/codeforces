#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int p[4];
int a, b;
int ans = 0;

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    for (int i = 0; i < 4; i++)
        scanf("%d", &p[i]);
    scanf("%d %d", &a, &b);
    while (a <= b)
    {
        sort(p, p + 4);
        int k = 0;

        do
        {
            int x = a;
            for (int i = 0; i < 4; i++)
                x %= p[i];
            k += x == a;
        } while (next_permutation(p, p + 4));
        ans += k >= 7;
        a++;
    }
    printf("%d\n", ans);
    return 0;
}