#include"bits/stdc++.h"
using namespace std;
int a[10000];
int pos[10000];
int dis[10000];
int cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        pos[i]=i;
        cin>>a[i];
        dis[a[i]]++;
    }
    sort(pos,pos+n,cmp);
    for(int i=0;i<10000;i++)dis[0]=max(dis[i],dis[0]);
    if(dis[0]<=k&&n>=k)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            a[pos[i]]=i%k+1;
        }
        for(int i=0;i<n;i++)
        {
            printf("%d%c",a[i]," \n"[i==n-1]);
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}