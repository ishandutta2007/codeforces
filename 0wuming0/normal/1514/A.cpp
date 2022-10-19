#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            int ok=0;
            for(int j=0;j<=100;j++)
            {
                if(j*j==a)
                {
                    ok=1;
                    break;
                }
            }
            if(ok==0)
            {
                ans=1;
            }
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}