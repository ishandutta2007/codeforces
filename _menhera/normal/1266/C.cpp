#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r, c; scanf("%d%d", &r, &c);
    if(c==1 && r==1)
    {
        puts("0"); return 0;
    }
    if(r==1)
    {
        for(int i=2; i<=c+1; ++i) printf("%d ", i);
        puts("");
    }
    else if(c==1)
    {
        for(int i=2; i<=r+1; ++i) printf("%d\n",i);
    }
    else
    {
        for(int i=1; i<=r; ++i, puts(""))
            for(int j=r+1; j<=r+c; ++j)
                printf("%d ", i*j/gcd(i, j));
    }
}