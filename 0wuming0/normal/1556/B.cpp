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
        int p=0,q=0;
        long long ans1=0,ans2=0;
        for(int i=1;i<=n;i++)
        {
            if(i%2)p--;
            else q--;
            if(a[i]%2)p++;
            else q++;
            ans1+=abs(p)+abs(q);
        }
        if(p!=0||q!=0)ans1=-2;
        p=q=0;
        for(int i=1;i<=n;i++)
        {
            if(i%2)p--;
            else q--;
            if(a[i]%2==0)p++;
            else q++;
            ans2+=abs(p)+abs(q);
        }
        if(p!=0||q!=0)ans2=-2;
        if(ans1==-2)ans1=ans2;
        if(ans2==-2)ans2=ans1;
        printf("%lld\n",min(ans1,ans2)/2);
    }
    return 0;
}