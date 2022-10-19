#include"bits/stdc++.h"
using namespace std;
int main()
{
    int a[100007],n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        sum+=a[i];
    }
    int s=0,i;
    for(i=0;i<n;i++)
    {
        s+=a[i];
        if(i==n-1)break;
        if(sum-s-a[i+1]<s)break;
    }
    cout<<i+1<<" "<<n-i-1<<endl;
    return 0;
}