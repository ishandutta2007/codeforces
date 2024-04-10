#include"bits/stdc++.h"
using namespace std;
int gcd(int a,int b)
{
    if(a==0||b==0)return a+b;
    return gcd(b,a%b);
}
int a[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        int ans=-1,bi;
        for(int i=0;i<n;i++)if(a[i]>ans)ans=a[bi=i];
        swap(a[0],a[bi]);
        int qq=a[0];
        for(int i=1;i<n;i++)
        {
            ans=-1;
            for(int j=i;j<n;j++)
            {
                if(gcd(qq,a[j])>ans)ans=gcd(a[bi=j],qq);
            }swap(a[i],a[bi]);qq=gcd(a[i],qq);
        }
        for(int i=0;i<n;i++)cout<<a[i]<<" \n"[i==n-1];
    }
    return 0;
}