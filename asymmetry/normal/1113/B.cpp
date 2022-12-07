#include <bits/stdc++.h>

using namespace std;

int n, a, mi=10000, ma, w, mw;
int t[50001];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a);
        mi=min(mi, a);
        w+=a;
        ++t[a];
    }
    for(int j=2; j<=100; ++j)
    {
        ma=0;
        for(int i=j; i<=100; i+=j)
        {
            if(t[i])
            {
                ma=max(i, ma);
            }
        }
        if(ma)
        {
            mw=max(mw, ma-(ma/j)-mi*j+mi);
        }
    }
    printf("%d", w-mw);
    return 0;
}