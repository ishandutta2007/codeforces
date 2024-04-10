#include <bits/stdc++.h>

using namespace std;

int n, a, ne, po;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &a);
        if(a<0)
        {
            ++ne;
        }
        if(a>0)
        {
            ++po;
        }
    }
    if(ne>=(n+1)/2)
    {
        printf("-1");
        return 0;
    }
    if(po>=(n+1)/2)
    {
        printf("1");
        return 0;
    }
    printf("0");
    return 0;
}