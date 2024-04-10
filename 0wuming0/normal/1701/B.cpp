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
        cout<<2<<endl;
        for(int i=1;i<=n;i+=2)
        {
            for(int j=1;i*j<=n;j=j*2)
            {
                printf("%d ",i*j);
            }
        }
        cout<<endl;
    }
    return 0;
}