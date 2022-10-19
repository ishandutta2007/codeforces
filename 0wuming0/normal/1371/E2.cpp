#include"bits/stdc++.h"
#define ll long long
using namespace std;
int main()
{
    int add=0;
    int a[100005];
    int num[100005]={0};
    int n,p;
    cin>>n>>p;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0;i<n;i++)add=max(add,a[i]-i-1);
    for(int i=0;i<n;i++)a[i]=max(1,a[i]-add);
    for(int i=0;i<n;i++)num[a[i]-1]++;
    for(int i=n-1;i>0;i--)num[i]+=num[i+1];
    for(int i=1;i<n;i++)num[n-i]=((num[n-i]-(i-1))%p+p)%p;
    int ans[100005]={0};
    for(int i=1;i<n;i++)
    {
        if(num[i]==0)num[i]=p;
        if(n-1-i<=n-num[i])
            ans[num[i]]=1;
    }
    int sum=0;
    for(int i=2;i<=p;i++)
    {
        if(ans[i]==0)sum++;
    }
    printf("%d\n",sum);
    for(int i=2,t=0;t<sum;i++)
    {
        if(ans[i]==0)
        {

            if(t)printf(" ");
            printf("%d",i-1+add);
            t++;
        }
    }
    putchar(10);
    return 0;
}