#include"bits/stdc++.h"
using namespace std;
int a[300005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        int l=-1,r=-3;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==0)
            {
                r=i;
                if(l<0)l=i;
            }
        }
        cout<<r-l+2<<endl;
    }
    return 0;
}