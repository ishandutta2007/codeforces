#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        for(int i=2*n,j=1;j<=n;j++,i+=2)
            cout<<i<<" ";cout<<endl;
    }
    return 0;
}