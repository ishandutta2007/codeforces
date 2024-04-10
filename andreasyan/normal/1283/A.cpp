#include <bits/stdc++.h>
using namespace std;

void solv()
{
    int h, m;
    scanf("%d%d", &h, &m);
    printf("%d\n", 24 * 60 - h * 60 - m);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}