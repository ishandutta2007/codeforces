#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        int u,r,l,d;u=r=100000;l=d=-100000;
        scanf("%d",&n);
        while(n--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int op;
            scanf("%d",&op);if(!op&&x>l)l=x;
            scanf("%d",&op);if(!op&&u>y)u=y;
            scanf("%d",&op);if(!op&&x<r)r=x;
            scanf("%d",&op);if(!op&&d<y)d=y;
        }
        if(r>=l&&u>=d)printf("1 %d %d\n",l,d);
        else printf("0\n");
    }
    return 0;
}
/*
4
2
-1 -2 0 0 0 0
-1 -2 0 0 0 0
3
1 5 1 1 1 1
2 5 0 1 0 1
3 5 1 0 0 0
2
1337 1337 0 1 1 1
1336 1337 1 1 0 1
1
3 5 1 1 1 1

1 -1 -2
1 2 5
0
1 -100000 -100000
*/