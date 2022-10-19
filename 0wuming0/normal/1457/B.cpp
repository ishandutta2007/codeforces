#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        //
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        int ans=1000000;
        for(int m=1;m<=100;m++)
        {
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]!=m)
                {
                    sum++;
                    i+=k-1;
                }
            }
            ans=min(ans,sum);
        }
        cout<<ans<<endl;

    }
    return 0;
}