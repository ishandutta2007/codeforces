#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
void p1(int n)
{
    int i;
    for(i=0;i<n;i++)
        putchar('1');
}
void p3(int n)
{
    int i;
    for(i=0;i<n;i++)
        putchar('3');
}
void p7(int n)
{
    int i;
    for(i=0;i<n;i++)
        putchar('7');
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {//
        //1000*1001/2
        //33*34/2
        //
        int n;
        scanf("%d",&n);
        int a,b,c;
        a=n/(1000*1001/2);
        n%=(1000*1001/2);
        b=n/(33*34/2);
        n%=(33*34/2);
        c=n;
        p1(a);
        p3(1001-34);
        p1(b);
        p3(32);
        p1(c);
        p3(2);
        p7(1);
        putchar(10);
    }
    return 0;
}
/*

*/