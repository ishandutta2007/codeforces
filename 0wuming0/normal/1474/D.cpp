#include"bits/stdc++.h"
using namespace std;
int a[200005];
int b[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        int flag=0;
        int now;
        for(int i=1;i<n;i++)
        {
            if(flag)
            {
                b[i]=-1;
                continue;
            }
            b[i]=a[i-1]-b[i-1];
            if(b[i]<0)flag=1;
        }
        if(a[n-1]==b[n-1])
        {
            cout<<"YES"<<endl;goto ed;
        }
        if(a[n-1]-a[n-2]==b[n-2]&&b[n-2]>=0)
        {
            cout<<"YES"<<endl;goto ed;
        }
        if(n==2)
        {
            cout<<"NO"<<endl;goto ed;
        }
        for(int ch=n-3;ch>=0;ch--)
        {
            if(a[ch]-a[ch+2]>=0&&b[ch]>=0&&a[ch+1]-(a[ch]-a[ch+2])==b[ch])
            {
                cout<<"YES"<<endl;goto ed;
            }
            a[ch+1]-=a[ch+2];
            if(a[ch+1]<0)break;
        }
        cout<<"NO"<<endl;goto ed;
        ed:;
    }
    return 0;
}