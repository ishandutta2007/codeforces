#include <bits/stdc++.h>

using namespace std;

int n, v, w;

int main()
{
    scanf("%d%d", &n, &v);
    if(v>=n-1)
    {
        printf("%d", n-1);
    }
    else
    {
        w=v;
        for(int i=2; i<=n-v; ++i)
        {
            w+=i;
        }
        printf("%d", w);
    }
    return 0;
}