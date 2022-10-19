#include <bits/stdc++.h>
using namespace std;
const int N = 10004;

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int n, s;
        scanf("%d%d", &n, &s);
        int ans = 0;
        ans += (s % n) * ((s / n) + 1) * ((s / n) + 1);
        ans += (n - (s % n)) * (s / n) * (s / n);
        printf("%d\n", ans);
    }
    return 0;
}