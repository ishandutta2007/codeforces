#include"bits/stdc++.h"
using namespace std;
struct data
{
    int a[10];
    bool operator<(const data& b)const
    {
         for(int i=0;i<10;i++)
         {
             if(a[i]!=b.a[i])return a[i]<b.a[i];
         }
         return 1<1;
    }
}null;
int a[10][200005];
int c[10];
int n;
set<data>mp,stute;
multimap<int,data>save;
void add(int now,data d)
{
    if(mp.find(d)==mp.end())
    {
        for(int i=0;i<n;i++)printf("%d%c",d.a[i]," \n"[i==n-1]);
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        d.a[i]--;
        if(stute.find(d)!=stute.end())
        {
            d.a[i]++;
            continue;
        }
        stute.insert(d);
        save.insert(make_pair(now+(a[i][d.a[i]+1]-a[i][d.a[i]]),d));
        d.a[i]++;
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        for(int j=1;j<=c[i];j++)scanf("%d",&a[i][j]);
    }
    int m;
    cin>>m;
    while(m--)
    {
        data temp=null;
        for(int i=0;i<n;i++)scanf("%d",&temp.a[i]);
        mp.insert(temp);
    }
    for(int i=0;i<n;i++)null.a[i]=c[i];
    for(int i=0;i<n;i++)a[i][0]=-1e9-1e8-1e7;/*
    for(int i=0;i<n;i++)
    {
        mp.insert(a[c[i]]-a[c[i]-1],i);
    }*/
    add(-1000000000,null);
    while(1)
    {
        int now=save.begin()->first;
        auto d=save.begin()->second;
        save.erase(save.begin());
        add(now,d);
    }
    return 0;
}