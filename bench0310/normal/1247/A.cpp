#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==b) printf("%d0 %d1\n",a,b);
    else if(a+1==b) printf("%d9 %d0\n",a,b);
    else if(a==9&&b==1) printf("99 100\n");
    else printf("-1\n");
    return 0;
}