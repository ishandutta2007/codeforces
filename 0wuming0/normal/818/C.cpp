#include"bits/stdc++.h"
using namespace std;
int l[100005],r[100005],u[100005],d[100005];
int l2[100005],r2[100005],u2[100005],d2[100005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int s;
    int n,m;
    cin>>s>>n>>m;
    n=s;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",l+i,u+i,r+i,d+i);
        l2[i]=min(l[i],r[i]);
        r2[i]=max(l[i],r[i]);
        u2[i]=min(u[i],d[i]);
        d2[i]=max(u[i],d[i]);
        l[i]=l2[i];
        u[i]=u2[i];
        r[i]=r2[i];
        d[i]=d2[i];
    }
    sort(l+1,l+1+n);
    sort(r+1,r+1+n,cmp);
    sort(u+1,u+1+n);
    sort(d+1,d+1+n,cmp);
    int aaa,bbb,ccc,ddd;
    cin>>ccc>>ddd>>aaa>>bbb;
    l[0]=u[0]=r[n+1]=d[n+1]=-1;
    r[0]=d[0]=l[n+1]=u[n+1]=1e9;
    for(int i=1;i<=n;i++)
    {
        int aa=aaa,bb=bbb,cc=ccc,dd=ddd;
        if(r2[i]!=l2[i])cc++,dd++;
        if(u2[i]!=d2[i])aa++,bb++;
        if(r2[i]>l[cc]&&l2[i]<r[dd]&&d2[i]>u[aa]&&u2[i]<d[bb]
           &&r2[i]<=l[cc+1]&&l2[i]>=r[dd+1]&&d2[i]<=u[aa+1]&&u2[i]>=d[bb+1])
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}