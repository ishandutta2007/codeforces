#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int mn = INT_MAX, mx = INT_MIN;
        while(n--)
        {
            int x;
            scanf("%d", &x);
            mn = min(mn, x), mx = max(mx, x);
        }
        printf("%d\n", mx - mn);
    }
    return 0;
}