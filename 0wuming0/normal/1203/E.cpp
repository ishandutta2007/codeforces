#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int a[150005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    int now=0,sum=0;
    for(int i=0;i<n;i++)
    {
        if(now<=a[i])
        {
            if(now==a[i])now=a[i]+1,sum++;
            else if(now==a[i]-1)now=a[i],sum++;
            else now=a[i]-1,sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
/*

*/