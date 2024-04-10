#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    int res=0;
    if(e>=f)
    {
        while(a>0&&d>0)
        {
            res+=e;
            a--;
            d--;
        }
        while(b>0&&c>0&&d>0)
        {
            res+=f;
            b--;
            c--;
            d--;
        }
    }
    else
    {
        while(b>0&&c>0&&d>0)
        {
            res+=f;
            b--;
            c--;
            d--;
        }
        while(a>0&&d>0)
        {
            res+=e;
            a--;
            d--;
        }
    }
    printf("%d\n",res);
    return 0;
}