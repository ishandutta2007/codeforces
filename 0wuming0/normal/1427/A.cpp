#include"bits/stdc++.h"
using namespace std;
int a[100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
        }
        if(sum>0)
        {
            for(int i=0;i<n;i++)a[i]=-a[i];
        }for(int i=0;i<n;i++)if(a[i]==0)a[i]=100;
        if(sum==0)cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            sort(a,a+n);
            for(int i=0;i<n;i++)if(a[i]==100)a[i]=0;
            if(sum>0)for(int i=0;i<n;i++)a[i]=-a[i];
            for(int i=0;i<n;i++)printf("%d%c",a[i]," \n"[n==i+1]);
        }
    }
    return 0;
}