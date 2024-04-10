#include"stdio.h"
#include"string.h"
int main()
{
    int n,m,a;
    scanf("%d%d%d",&n,&m,&a);
    printf("%lld\n",((long long)(n-1)/a+1)*((m-1)/a+1));
    return 0;
}