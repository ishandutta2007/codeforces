#include<iostream>
#include<algorithm>
#include"stdio.h"
using namespace std;
int n;
long long ans[3005];
struct marble
{
    int a;
    int b;
}m[3005];
operator<(marble m,marble n)
{
    return m.a<n.a;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&m[i].a,&m[i].b);
    }
    sort(m,m+n);
    long long sum;
    //for(int i=0;i<n;i++){cout<<m[i].a<<m[i].b<<endl;}
    for(int i=0;i<n;i++)
    {
        sum=i==0?0:ans[i-1];
        for(int j=0;j<i;j++)
        {
            if(ans[j]<sum)sum=ans[j];
        }
        ans[i]=sum+m[i].b;
        for(int j=0;j<i;j++)
        {
            ans[j]=ans[j]+m[i].a-m[j].a;
        }
    }
    sum=ans[0];
    for(int i=0;i<n;i++)if(ans[i]<sum)sum=ans[i];
    cout<<sum<<endl;
    return 0;
}