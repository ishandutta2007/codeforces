#include"bits/stdc++.h"
using namespace std;
int a[200005];
int ans[500005],l,r;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        l=r=300000;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        if(a[0]==n)
        {
            for(int i=1,j=n-1;i<j;i++,j--)swap(a[i],a[j]);
            for(int i=0;i<n;i++)printf("%d%c",a[i]," \n"[i==n-1]);
        }
        else if(a[n-1]==n)
        {
            for(int i=0,j=n-2;i<j;i++,j--)swap(a[i],a[j]);
            for(int i=0;i<n;i++)printf("%d%c",a[i]," \n"[i==n-1]);
        }
        else printf("-1\n");
    }
    return 0;
}