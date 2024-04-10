#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        int sum=0;
        for(int i=0;i<n;i++)sum=(sum+a[i])%x;
        if(sum)
        {
            cout<<n<<endl;
        }
        else
        {
            int i;
            for(i=0;i<n;i++)
            {
                if(a[i]%x)break;
            }
            if(i==n)cout<<-1<<endl;
            else
            {
                int ans=n-i-1;
                for(i=n-1;i>=0;i--)
                {
                    if(a[i]%x)break;
                }
                ans=max(ans,i);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}