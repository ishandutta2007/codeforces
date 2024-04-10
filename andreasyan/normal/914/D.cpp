#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int gcd(int x,int y)
{
    if(x==0)
        return y;
    if(x>y)
        return gcd(y,x);
    return gcd(y%x,x);
}

int n;
int a[N];

int t[N*4];
void bil(int tl,int tr,int pos)
{
    if(tl==tr)
    {
        t[pos]=a[tl];
        return;
    }
    int m=(tl+tr)/2;
    bil(tl,m,pos*2);
    bil(m+1,tr,pos*2+1);
    t[pos]=gcd(t[pos*2],t[pos*2+1]);
}
void ubd(int tl,int tr,int x,int pos)
{
    if(tl==tr)
    {
        t[pos]=a[x];
        return;
    }
    int m=(tl+tr)/2;
    if(x<=m)
        ubd(tl,m,x,pos*2);
    else
        ubd(m+1,tr,x,pos*2+1);
    t[pos]=gcd(t[pos*2],t[pos*2+1]);
}
int ans;
void qry(int tl,int tr,int l,int r,int pos,int x)
{
    int m=(tl+tr)/2;
    if(tl==l && tr==r)
    {
        if(ans>=2)
            return;
        if(t[pos]%x==0)
            return;
        if(tl==tr)
        {
            ++ans;
            return;
        }
        if(t[pos*2]%x && t[pos*2+1]%x)
        {
            ans+=2;
            return;
        }
        qry(l,m,l,m,pos*2,x);
        qry(m+1,r,m+1,r,pos*2+1,x);
        return;
    }
    if(r<=m)
        qry(tl,m,l,r,pos*2,x);
    else if(l>m)
        qry(m+1,tr,l,r,pos*2+1,x);
    else
    {
        qry(tl,m,l,m,pos*2,x);
        qry(m+1,tr,m+1,r,pos*2+1,x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    bil(1,n,1);
    int q;
    cin>>q;
    while(q--)
    {
        int o;
        cin>>o;
        if(o==1)
        {
            ans=0;
            int l,r,x;
            cin>>l>>r>>x;
            qry(1,n,l,r,1,x);
            if(ans<=1)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
        {
            int i,x;
            cin>>i>>x;
            a[i]=x;
            ubd(1,n,i,1);
        }
    }
    return 0;
}