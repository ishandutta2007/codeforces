#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)cout<<0<<endl;
        else if(n<=3)cout<<n-1<<endl;
        else if(n%2)
        {
            cout<<3<<endl;
        }
        else cout<<2<<endl;
    }
    return 0;
}