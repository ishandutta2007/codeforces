#include"bits/stdc++.h"
using namespace std;
int a[100005];
int b[100005];
int pos[100005];
int cmp(int x,int y)
{
    if(a[x]==a[y])return b[x]<b[y];
    return a[x]<a[y];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",a+i,b+i);
        pos[i]=i;
    }
    sort(pos,pos+n,cmp);
    for(int i=0;i<n-1;i++)
    {
        if(a[pos[i]]<a[pos[i+1]]&&b[pos[i]]>b[pos[i+1]])
        {
            cout<<"Happy Alex"<<endl;
            return 0;
        }
    }cout<<"Poor Alex"<<endl;
    return 0;
}