#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            ans+=a;
        }
        if(ans==k)puts("YES");
        else puts("NO");
    }
    return 0;
}