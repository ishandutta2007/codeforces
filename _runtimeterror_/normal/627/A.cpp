#include<iostream>
using namespace std;

int main()
{
    long long s,x;
    scanf("%lld %lld",&s,&x);

    long long ans = 1;

    bool canTake[42]={false};

    for(int j=0;j<=40;++j)
    {
        if(x&(1LL<<j))
            ans *= 2, s -= 1LL<<j;
        else
            canTake[j+1] = true;
    }   

    if(!s && ans>1)
        ans -= 2;
    for(int j=0;j<=40;++j)
        if(s&(1LL<<j))
            ans *= canTake[j];

    printf("%lld\n",ans);
}