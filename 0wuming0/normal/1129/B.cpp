#include"bits/stdc++.h"
using namespace std;
int a[2005];
int main()
{
    int k;
    cin>>k;
    int t;
    //if(k<=1e6)
    for(t=999999;;t--)
    {
        if((k+t)%1500==0)break;
    }
    a[1]=t;
    a[2]=-(t+1);
    a[1500]=(k+t)/1500+1498;//cout<<(k+t)/1500<<endl;
    a[1501]=-1e6;
    for(int i=3;i<1500;i++)a[i]=-1;
    if(a[1500]<4000)
    {
        a[500]=(k+t)/500+498;//cout<<(k+t)/1500<<endl;
        a[501]=-1e6;
        int n=501;
        cout<<501<<endl;
        for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
        int sum=0;
        for(int i=1;i<=500;i++)sum+=a[i];
        //cout<<sum*500<<endl;
        return 0;
    }
    cout<<1501<<endl;
    int n=1501;
    int sum=0;
    for(int i=1;i<=1500;i++)sum+=a[i];
    //cout<<sum*1500<<endl;
    for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}