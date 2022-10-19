#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l,r;
    for(l=1;l<n;l++)if(a[l]>=a[l+1])break;
    for(r=n;r>1;r--)if(a[r]>=a[r-1])break;
    for(int i=l;i<=r;i++)if(a[l]!=a[i])
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}