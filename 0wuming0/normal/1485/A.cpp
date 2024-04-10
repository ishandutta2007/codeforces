#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int ans=1e9;
        for(int i=b;i<b+1000;i++)
        {
            if(i<=1)continue;
            int k=a;
            int num=i-b;
            while(k)
            {
                num++;
                k/=i;
            }
            ans=min(ans,num);
        }
        cout<<ans<<endl;
    }
    return 0;
}