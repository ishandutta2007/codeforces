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
    int t;
    cin>>t;
    while(t--)
    {
        int n,a[205],b[205],d;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        for(int i=0;i<n;i++)if(a[i]==n)d=i;
        int p=0;
        for(int i=d+1;i<n;i++)
        {
            b[p]=a[i];
            p++;
        }
        for(int i=0;i<=d;i++)
        {
            b[p]=a[i];
            p++;
        }
        int i;
        for(i=0;i<n;i++)
        {
            if(b[i]!=i+1)break;
        }
        if(i==n){printf("YES\n");continue;}

        for(int i=0;i<n;i++)if(a[i]==1)d=i;
        p=0;
        for(int i=d+1;i<n;i++)
        {
            b[p]=a[i];
            p++;
        }
        for(int i=0;i<=d;i++)
        {
            b[p]=a[i];
            p++;
        }
        for(i=0;i<n;i++)
        {
            if(b[i]+i!=n)break;
        }
        if(i==n){printf("YES\n");continue;}

        {printf("NO\n");continue;}
    }
    return 0;
}
/*
5
4
1 2 3 4
3
1 3 2
5
1 2 3 5 4
1
1
5
4 5 1 2 3
*/