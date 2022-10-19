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
    ll sum=0;
    ll n,a[100005],aa=0,b=0,c=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",a+i);
        if(a[i]==0)c++;
        if(a[i]<0)aa++,sum+=-1-a[i];
        if(a[i]>0)b++,sum+=a[i]-1;
    }
    aa%=2;
    if(aa)
    {
        if(c)sum+=c;
        else sum+=2ll;
    }
    else
        sum+=c;
    cout<<sum<<endl;
    return 0;
}
/*

*/