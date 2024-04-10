#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
void re(char *a)
{
    char *p,*q,t;
    p=q=a;
    while(*q)q++;q--;
    for(;p<q;p++,q--)t=*p,*p=*q,*q=t;
}
int main()
{
    int n,i,t;
    char x[100005],y[100005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",x);
        scanf("%s",y);
        re(x);
        re(y);
        //puts(x);
        int t=0;
        while(y[t]=='0')t++;
        int p=t;
        while(x[p]=='0')p++;
        printf("%d\n",p-t);
    }
    return 0;
}
/*
4
1010
11
10001
110
1
1
1010101010101
11110000
*/