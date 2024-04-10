#include"bits/stdc++.h"
using namespace std;
int a[105];
int main()
{
    int n;
    cin>>n;
    if(n>100)cout<<"1"<<endl;
    else
    {
        int ans=10000;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=1;i<n;i++)
        {
            int aa=0;
            for(int j=i;j>=1;j--)
            {
                aa^=a[j];
                int bb=0;
                for(int k=i+1;k<=n;k++)
                {
                    bb^=a[k];
                    if(aa>bb)
                    {
                        ans=min(ans,k-j-1);
                    }
                }
            }
        }
        if(ans==10000)ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}