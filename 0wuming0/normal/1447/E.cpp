#include"bits/stdc++.h"
using namespace std;
int a[200005],nn,ans[200005];
int solve(int a[],int n,int xors)
{
    if(n<=2)return n;
    int ans=0,anss;
    #define a xors^a
    int t=1,now=0,p,last;
    while((a[n-1])>=(1<<t))
    {
        t++;
    }
    t--;
    p=(1<<t);
    for(last=now;last<n;last++)
    {
        if((a[last])>=p)break;
    }
    #undef a
    if(last!=now)
    {
        anss=solve(a+now,last-now,xors);
        if(last-now!=n)anss++;
        ans=max(ans,anss);
    }
    if(last!=n)
    {
        now=last;
        last=n;
        anss=solve(a+now,last-now,xors^p);
        if(last-now!=n)anss++;
        ans=max(ans,anss);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    cout<<n-solve(a,n,0)<<endl;
    return 0;
}