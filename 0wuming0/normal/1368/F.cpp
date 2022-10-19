#include"bits/stdc++.h"
using namespace std;
int a[1005];
int b[1005];
int main()
{
    int n;
    cin>>n;
    if(n<=3)
    {
        cout<<0<<endl;
        return 0;
    }
    int ans=0,m;
    for(int i=1;i<=n;i++)
    {
        int k=n/(i+1);
        if(n%(i+1))k++;
        k+=i;
        if(n-k>ans)
        {
            m=i+1;
            ans=n-k;
        }
    }
    //cout<<"<<"<<ans<<endl;
    for(int i=1;i<=n;i++)if(i%m)a[i]=1;
    a[n]=0;
    while(1)
    {
        int s=0;
        for(int i=1;i<=n;i++)s+=b[i];
        if(s>=ans)
        {
            cout<<0<<endl;
            break;
        }
        s=0;
        for(int i=1;i<=n;i++)if(a[i]!=b[i])s++;
        cout<<s;
        for(int i=1;i<=n;i++)if(a[i]!=b[i])cout<<" "<<i;
        cout<<endl;
        for(int i=1;i<=n;i++)b[i]=a[i];
        int x;
        cin>>x;
        for(int i=1;i<=s;i++)
        {
            b[x]=0;
            if(x==n)x=1;
            else x++;
        }
    }
    return 0;
}