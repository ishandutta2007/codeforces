#include"bits/stdc++.h"
using namespace std;
int a[200005];
int b[200005];
int ans;
int qus(int i)
{
    if(i<=0)return 0;
    cout<<"? "<<i<<endl;
    int k;
    cin>>k;
    if(k)ans=min(k*i,ans);
    return k;
}
int main()
{
    int n;
    cin>>n;
    int l=0,r=4e6+5;
    while(l+1!=r)
    {
        int m=l+r>>1;
        cout<<"? "<<m<<endl;
        int k;
        cin>>k;
        if(k==0||k>=2)l=m;
        else r=m;
    }
    ans=r;/*
    int num=n+5;
    for(int i=r-1;i>=1;i--)
    {
        num--;
        if(num==0)break;
        qus(i);
    }*/
    //r-n+1;
    for(int i=1;i<=n+5;i++)
    {
        int d=(r+1-i)/i;
        if((r+1-i)%i)d++;
        qus(d);
    }
    cout<<"! "<<ans<<endl;
    return 0;
}