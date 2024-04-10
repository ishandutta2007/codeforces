#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    int ans=0;
    for(int i=1;i<=n;)
    {
        int j;
        for(j=i+1;;j++)
        {
            if(a[i]!=a[j])break;
        }//cout<<i<<j<<endl;
        ans+=max(0,j-i-2);
        i=j;
    }//cout<<ans<<endl;
    for(int i=3;i<n;i++)
    {
        if(a[i]!=a[i+1]&&a[i-1]==a[i+1]&&a[i-1]==a[i-2])
        {
            int t=a[i+1];
            int j=i+2;
            be:;
            if(a[j]==t)
            {
                ans++;
            }
            else if(a[j+1]==t)
            {
                j+=2;
                goto be;
            }
            i=j;
        }
    }
    cout<<n-ans<<endl;
    return 0;
}
/*
7
2 2 1 2 2 2 2
*/