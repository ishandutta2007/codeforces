#include"bits/stdc++.h"
using namespace std;
int a[200005];
int num[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<int>s;
        int ans=10000000;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        for(int i=0;i<=n;i++)num[i]=-100000000;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,i-num[a[i]]+1);
            num[a[i]]=i;
        }
        if(ans==10000000)ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}