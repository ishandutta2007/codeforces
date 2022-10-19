#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
char a[N];

int main()
{
    scanf("%d %s", &n, a);
    int la = N, ra = -1;
    int lb = N, rb = -1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'A')
        {
            if (la == N)
                la = i;
            ra = i;
        }
        else
        {
            if (lb == N)
                lb = i;
            rb = i;
        }
    }
    long long ans = (n * 1LL * (n + 1)) / 2;
    for (int i = 0; i < n; ++i)
    {
        --ans;
        if (a[i] == 'A')
        {
            if (lb < i)
            {
                if (a[i - 1] == 'A')
                    --ans;
            }
            if (i < rb)
                --ans;
        }
        else
        {
            if (la < i)
            {
                if (a[i - 1] == 'B')
                    --ans;
            }
            if (i < ra)
                --ans;
        }
    }
    cout << ans << endl;
    return 0;
}