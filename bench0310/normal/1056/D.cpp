#include <bits/stdc++.h>
using namespace std;
int a[100005],c[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        if(!c[i]) c[i]=1;
        c[a[i]]+=c[i];
    }
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++) cout<<c[i]<<" ";
    return 0;
}