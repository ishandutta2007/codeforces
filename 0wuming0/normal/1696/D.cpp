#include"bits/stdc++.h"
using namespace std;
int a[1000005];
int pos[1000005];
int mnl[300005];
int mxl[300005];
int mnr[300005];
int mxr[300005];
int solvel(int p,int op)
{
    if(p==1)return 0;
    if(op==1)
    {
        return solvel(pos[mxl[p-1]],op^1)+1;
    }
    else
    {
        return solvel(pos[mnl[p-1]],op^1)+1;
    }
}
int n;
int solver(int p,int op)
{
    if(p==n)return 0;
    if(op==1)
    {
        return solver(pos[mxr[p+1]],op^1)+1;
    }
    else
    {
        return solver(pos[mnr[p+1]],op^1)+1;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            pos[a[i]]=i;
        }
        mnl[1]=mxl[1]=a[1];
        for(int i=2;i<=n;i++)
        {
            mnl[i]=min(mnl[i-1],a[i]);
            mxl[i]=max(mxl[i-1],a[i]);
        }
        mnr[n]=mxr[n]=a[n];
        for(int i=n-1;i>=1;i--)
        {
            mnr[i]=min(mnr[i+1],a[i]);
            mxr[i]=max(mxr[i+1],a[i]);
        }
        int l=pos[1],r=pos[n];
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        int ans;
        if(l<r)
        {
            ans=solvel(l,1)+solver(r,0)+1;
        }
        else
        {
            ans=solvel(r,0);
            ans+=solver(l,1);
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}