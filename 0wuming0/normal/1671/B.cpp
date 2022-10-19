#include"bits/stdc++.h"
using namespace std;
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        bool f1=1,f2=1,f3=1;
        for(int i=1;i<=n;i++)
        {
            if(abs((a[1]-2+i)-a[i])>1)f1=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(abs((a[1]-1+i)-a[i])>1)f2=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(abs((a[1]-0+i)-a[i])>1)f3=0;
        }
        if(f1||f2||f3)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}