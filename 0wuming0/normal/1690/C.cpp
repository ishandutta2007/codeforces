#include"bits/stdc++.h"
using namespace std;
int a[200005],b[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=0;i<n;i++)scanf("%d",b+i);
        int now=0;
        for(int i=0;i<n;i++)
        {
            if(now<a[i])now=a[i];
            printf("%d%c",b[i]-now," \n"[i==n-1]);
            now=b[i];
        }
    }
    return 0;
}