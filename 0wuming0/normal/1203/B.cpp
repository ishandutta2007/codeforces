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
        int n,a[405],b[405];
        scanf("%d",&n);
        n*=4;
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        for(int i=0;i<n;i+=2)
        {
            if(a[i]==a[i+1])
                b[i/2]=a[i];
            else
            {
                goto no;
            }
        }
        n/=4;
        for(int i=0;i<n;i++)
        {
            b[i]*=b[2*n-i-1];
        }
        int i;
        for(i=1;i<n;i++)
        {
            if(b[0]!=b[i])break;
        }
        if(i==n){printf("YES\n");continue;}
        no:printf("NO\n");
    }
    return 0;
}
/*
5
1
1 1 10 10
2
10 5 2 10 1 2 2 5
2
10 5 1 10 5 1 1 1
2
1 1 1 1 1 1 1 1
1
10000 10000 10000 10000
*/