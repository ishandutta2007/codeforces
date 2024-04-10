#include"bits/stdc++.h"
using namespace std;
int a[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int now=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        while(1)
        {
            int i;
            for(i=1;i<n;i++)if(a[i]>a[i+1])break;
            if(i==n)break;
            now++;
            if(now%2){for(i=2;i<=n;i+=2)if(a[i-1]>a[i])swap(a[i-1],a[i]);}
            else for(i=2;i<n;i+=2)if(a[i]>a[i+1])swap(a[i+1],a[i]);
        }
        cout<<now<<endl;
    }
    return 0;
}