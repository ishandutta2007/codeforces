#include"bits/stdc++.h"
using namespace std;
int n;
int a[150005],b[150005];
int prime[10005];
void check(int p)
{
    if(p==1)return;
    for(int i=0;i<n;i++)
    {
        if(a[i]%p&&b[i]%p)return;
    }
    cout<<p<<endl;
    exit(0);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",a+i,b+i);
    }
    for(int i=2;i<=100;i++)
    {
        if(i>=10&&(i%2==0||i%3==0||i%5==0||i%7==0))continue;
        check(i);
    }
    {
        int t=a[0];
        for(int i=2;i<=100;i++)while(t%i==0)t/=i;
        for(int i=1;i<=50000;i++)if(t%i==0)
        {
            check(i);
            check(t/i);
        }
    }
    {
        int t=b[0];
        for(int i=2;i<=100;i++)while(t%i==0)t/=i;
        for(int i=1;i<=50000;i++)if(t%i==0)
        {
            check(i);
            check(t/i);
        }
    }
    cout<<-1<<endl;
    return 0;
}