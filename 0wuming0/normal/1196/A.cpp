#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int i,j,k,n,m,t;
    ll a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&c);
        printf("%lld\n",(a+b+c)/2);
    }
    return 0;
}
/*
4
1 3 4
1 10 100
10000000000000000 10000000000000000 10000000000000000
23 34 45

4
55
15000000000000000
51
*/