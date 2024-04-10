#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=0;
        scanf("%d",&n);
        int t,op=0,p,ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            if(op==0&&t==1)op=1,p=i;
            else if(op==1&&t==1)ans+=i-p-1,p=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}