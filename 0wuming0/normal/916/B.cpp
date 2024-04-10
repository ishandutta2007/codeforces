#include"bits/stdc++.h"
using namespace std;
int a[200005];
int ans[200005],nn;
int main()
{
    long long n;
    int k;
    cin>>n>>k;
    for(int i=0;(1ll<<i)<=n;i++)
    {
        if((1ll<<i)&n)a[i+150000]++,k--;
    }
    if(k<0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=200004;;i--)
    {
        if(a[i])
        {
            if(a[i]>k)break;
            else
            {
                a[i-1]+=a[i]*2;
                k-=a[i];
                a[i]=0;
            }
        }
    }
    for(int i=0;;i++)
    {
        if(a[i])
        {
            while(k--)
            {
                a[i]--;
                a[--i]+=2;
            }
            break;
        }
    }
    cout<<"Yes"<<endl;
    for(int i=200004;i>=0;i--)
    {
        while(a[i]--)ans[nn++]=i-150000;
    }
    for(int i=0;i<nn;i++)printf("%d%c",ans[i]," \n"[i==nn-1]);
    return 0;
}