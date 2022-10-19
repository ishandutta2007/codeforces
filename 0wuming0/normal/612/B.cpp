#include"bits/stdc++.h"
using namespace std;
int a[200006];
int pos[200006];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        pos[a[i]]=i;
    }
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        ans+=abs(pos[i]-pos[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}