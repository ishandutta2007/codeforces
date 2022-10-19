#include"bits/stdc++.h"
using namespace std;
int mod=998244353;
int x;
int _2[150005];
int solve2(int a[],int an,int b[],int bn,int p)
{
    if(an==0||bn==0)return 0;
    if(p==-1)
    {
        return ((_2[an+bn]+1-_2[an]-_2[bn])%mod+mod)%mod;
    }
    int al=0,bl=0,ar=an-1,br=bn-1;
    for(;al<=ar;)
    {
        if(a[al]&(1<<p))
        {
            swap(a[al],a[ar]);
            ar--;
        }
        else al++;
    }
    for(;bl<=br;)
    {
        if(b[bl]&(1<<p))
        {
            swap(b[bl],b[br]);
            br--;
        }
        else bl++;
    }
    if(x&(1<<p))
    {
        long long ans1=solve2(a,al,b+bl,bn-bl,p-1),ans2=solve2(a+al,an-al,b,bl,p-1);
        return ((_2[al+bl]+_2[an+bn-al-bl]+2ll-_2[al]-_2[bl]-_2[an-al]-_2[bn-bl]+ans1*(_2[an-al]+_2[bl]-1)%mod+ans2*(_2[al]+_2[bn-bl]-1)%mod+ans1*ans2%mod)%mod+mod)%mod;
    }
    else
    {
        return (solve2(a,al,b,bl,p-1)+solve2(a+al,an-al,b+bl,bn-bl,p-1))%mod;
    }
}
int solve(int a[],int n,int p)
{
    if(n==0)return 0;
    if(p==-1)
    {
        return _2[n]-1;
    }
    int l=0,r=n-1;
    for(;l<=r;)
    {
        if(a[l]&(1<<p))
        {
            swap(a[l],a[r]);
            r--;
        }
        else l++;
    }
    if(x&(1<<p))return ((_2[l]+_2[n-l]-2)%mod+solve2(a,l,a+l,n-l,p-1))%mod;
    return (solve(a,l,p-1)+solve(a+l,n-l,p-1))%mod;
}
int a[150005];
int main()
{
    int n;
    cin>>n>>x;
    _2[0]=1;
    for(int i=1;i<=n;i++)
    {
        _2[i]=_2[i-1]*2%mod;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    cout<<solve(a,n,29)<<endl;
    return 0;
}