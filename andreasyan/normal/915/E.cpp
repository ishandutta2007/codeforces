#include <bits/stdc++.h>
using namespace std;
const int N=18000003;

int n;

int t[N];
int z;
int ll[N],rr[N];
void av(int tl,int tr,int pos)
{
    if(tl==tr)
        return;
    if(!ll[pos])
        ll[pos]=++z;
    if(!rr[pos])
        rr[pos]=++z;
}
void sh(int tl,int tr,int pos)
{
    int m=(tl+tr)/2;
    if(t[pos]==0)
    {
        t[ll[pos]]=0;
        t[rr[pos]]=0;
    }
    if(t[pos]==(tr-tl+1))
    {
        t[ll[pos]]=m-tl+1;
        t[rr[pos]]=tr-(m+1)+1;
    }
}
void ubd(int tl,int tr,int l,int r,int pos,int k)
{
    if(tl==l && tr==r)
    {
        if(k==1)
        {
            t[pos]=0;
        }
        else
        {
            t[pos]=(r-l+1);
        }
        return;
    }
    av(tl,tr,pos);
    sh(tl,tr,pos);
    int m=(tl+tr)/2;
    if(r<=m)
        ubd(tl,m,l,r,ll[pos],k);
    else if(l>m)
        ubd(m+1,tr,l,r,rr[pos],k);
    else
    {
        ubd(tl,m,l,m,ll[pos],k);
        ubd(m+1,tr,m+1,r,rr[pos],k);
    }
    t[pos]=t[ll[pos]]+t[rr[pos]];
}

int main()
{
    int q;
    scanf("%d%d",&n,&q);
    ubd(1,n,1,n,0,2);
    while(q--)
    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        ubd(1,n,l,r,0,k);
        printf("%d\n",t[0]);
    }
    return 0;
}