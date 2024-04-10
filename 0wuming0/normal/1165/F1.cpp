#include"bits/stdc++.h"
using namespace std;
int need[200005];
int a[200005];
vector<int>day[400005];
bool solve(int d)
{
    int s=0;
    for(int i=0;i<200005;i++)
    {
        s+=(need[i]=a[i]);
    }
    s*=2;
    int now=d;
    for(int i=d;i>=1;i--)
    {
        now=min(now,i);
        for(auto t:day[i])
        {
            int k=min(need[t],now);
            now-=k;
            need[t]-=k;
            s-=k;
        }
    }
    if(s>d)return false;
    else return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        day[a].push_back(b);
    }
    int x,x1=0,x2=400005;
    while(x1+1!=x2)
    {
        x=x1+x2>>1;
        if(solve(x))x2=x;
        else x1=x;
    }
    cout<<x2<<endl;
    return 0;
}