#include"bits/stdc++.h"
using namespace std;int a[200004];
int main()
{
    int n;
    cin>>n;
    //
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    int maxs=a[0];
    for(int i=1;i<n;i++)
    {
        a[i]+=maxs;
        maxs=max(maxs,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d%c",a[i]," \n"[n==i+1]);
    }
    return 0;
}