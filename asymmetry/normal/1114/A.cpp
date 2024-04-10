#include <bits/stdc++.h>

using namespace std;

int a, b, c, x, y, z;

int main()
{
    scanf("%d%d%d%d%d%d", &x, &y, &z, &a, &b, &c);
    if(x<=a)
    {
        a-=x;
        x=0;
    }
    else
    {
        printf("NO");
        return 0;
    }
    if(y<=a)
    {
        a-=y;
        y=0;
    }
    else
    {
        y-=a;
        a=0;
    }
    if(y<=b)
    {
        b-=y;
        y=0;
    }
    else
    {
        printf("NO");
        return 0;
    }
    z-=a;
    z-=b;
    z-=c;
    if(z>0)
    {
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}