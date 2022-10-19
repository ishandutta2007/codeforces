#include"bits/stdc++.h"
using namespace std;
//int pos[1000005],nn;
//int num[1000005];
int a[1000005],n;
long long ans=0;
long long now=0;
long long solve(long long p)
{//cout<<nn<<endl;cout<<num[0]<<endl;
    ans=0;/*
    int usel=0,user=0;
    for(int i=0;;)
    {
        if(i>=nn-1)break;
        int l=i,r,m;
        usel=(num[l]-user)%p;
        long long use=usel;
        int flag=1;
        if(use>p/2)flag=0,m=l;
        for(r=l+1;r<=nn;r++)
        {//cout<<r<<endl;
            if(flag&&((use+num[r])>p/2))
            {
                flag=0;
                m=r;
            }
            if(use+num[r]>=p)break;
            else use=use+num[r];
        }
        user=p-use;
        for(int j=l+1;j<r;j++)
        {
            ans=ans+abs(pos[j]-pos[m])*(long long)num[j];
        }
        ans=ans+abs(pos[l]-pos[m])*(long long)usel;
        ans=ans+abs(pos[r]-pos[m])*(long long)user;
        i=r;//cout<<l<<" "<<m<<" "<<r<<":"<<usel<<" "<<user<<"   "<<ans<<endl;
    }//cout<<p<<":"<<ans<<endl;*/
    now=0;
    for(int i=1;i<=n;i++)
    {
        now+=a[i];
        now%=p;
        ans+=min(now,p-now);
    }
    return ans;
}
int main()
{
    //int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        sum=sum+a[i];/*
        if(a[i])
        {
            pos[nn]=i;
            num[nn]=a[i];
            nn++;
        }*/
    }
    if(sum==1)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        long long ans0=(1ll<<62);
        for(int p=2;p<=1e6;p++)
        {
            if(sum%p==0)
            {
                ans0=min(ans0,solve(p));
                while(sum%p==0)sum/=p;
            }
        }
        if(sum!=1)ans0=min(ans0,solve(sum));
        cout<<ans0<<endl;
    }
    return 0;
}
/*
8
1 1 1 0 0 1 1 1
*/