#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        long long _0=0,_1=0,s=0;
        for(int i=2;i<n;i++){if(a[i]==0)_0++;
        else if(a[i]==1)_1++;s+=a[i];}
        if(_0+_1==n-2&&_1>0)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n==3&&a[2]%2==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(_0==n-3)
        {
            if(s%2==0)cout<<s/2<<endl;
            else if(s==3)cout<<-1<<endl;
            else cout<<(s-4+1)/2+3<<endl;
            continue;
        }
        for(int i=2;i<n;i++)s+=a[i]%2;
        cout<<s/2<<endl;
    }
    return 0;
}