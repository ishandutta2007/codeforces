#include<cstdio>
int main()
{
    long long n,m,a;
    scanf("%lld%lld%lld",&n,&m,&a);
    printf("%lld\n",((n-1)/a+1)*((m-1)/a+1));
}
//attempt 3:Fail to show the result on luogu.