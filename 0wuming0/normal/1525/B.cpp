#include"bits/stdc++.h"
using namespace std;
int a[10005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",a+i);bool flag=0;
        for(int i=1;i<=n;i++)if(a[i]!=i)flag=1;
        if(!flag)cout<<0<<endl;
        else
        if(a[1]==1||a[n]==n)cout<<1<<endl;
        else if(a[1]==n&&a[n]==1)cout<<3<<endl;
        else cout<<2<<endl;
        //cout<<100/__gcd(100,n)<<endl;
    }
    return 0;
}