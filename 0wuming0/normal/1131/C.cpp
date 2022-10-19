#include"bits/stdc++.h"
using namespace std;
int n;
int a[105];
int now[105];
int ch()
{
    int ans=abs(a[now[0]%n]-a[now[n-1]%n]);
    for(int i=1;i<n;i++)
    {
        ans=max(ans,abs(a[now[i]%n]-a[now[i-1]%n]));
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    int t=0;
    for(int i=1;i<n;i+=2)
    {
        now[t]=i;
        t++;
    }
    for(int i=(n%2==0?n-2:n-1);i>=0;i-=2)
    {
        now[t]=i;
        t++;
    }
    int ans=ch();
    for(int i=0;;i++)
    {
        for(int j=0;j<n;j++)now[j]++;
        int aw=ch();
        if(i>150&&ans==aw)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d%c",a[now[j]%n]," \n"[j==n-1]);
            }
            return 0;
        }
        ans=min(ans,aw);
    }
    return 0;
}
/*
*/