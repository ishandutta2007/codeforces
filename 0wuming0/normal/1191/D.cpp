#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    int a[100005];
    cin>>n;
    if(n==1)
    {
        int t;
        cin>>t;
        if(t%2)cout<<"sjfnb"<<endl;
        else cout<<"cslnb"<<endl;
    }
    else
    {
        for(int i=0;i<n;i++)scanf("%d",a+i);
        sort(a,a+n);
        int ans=0;
        for(int i=1;i<n;i++)if(a[i-1]==a[i]){ans++;if(a[i]==0)ans++;if(i>=2&&a[i-2]+1==a[i-1])ans++;};
        if(ans>=2)cout<<"cslnb"<<endl;
        else
        {
            ans=(n%4)*(n-1)/2%2;
            for(int i=0;i<n;i++)ans+=a[i]%2;
            ans%=2;
            if(ans)cout<<"sjfnb"<<endl;
            else cout<<"cslnb"<<endl;
        }
    }
    return 0;
}