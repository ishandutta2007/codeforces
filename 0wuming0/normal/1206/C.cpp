#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int a[100006],b[100006];
int main()
{
    int n;
    cin>>n;
    if(n%2==0)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
    {
        if(i%2)
            a[i]=i;
        else
            a[i]=2*n+2-i;
    }
    for(int i=1;i<=n;i++)
    {
        if(i%2)
            b[i]=i+1;
        else
            b[i]=2*n-i+1;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);
    putchar(10);
    return 0;
}
/*

*/