#include"bits/stdc++.h"
using namespace std;
int a[1004];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        a[x]++;
        cin>>x;
        a[x]++;
    }
    cout<<n-1<<endl;
    int t;
    for(int i=1;;i++)
    {
        if(a[i]==0)
        {
            t=i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=t)
        cout<<i<<" "<<t<<endl;
    }
    return 0;
}