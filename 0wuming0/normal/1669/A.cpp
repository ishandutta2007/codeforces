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
        int ans=1;
        if(n<=1899)ans=2;
        if(n<=1599)ans=3;
        if(n<=1399)ans=4;
        printf("Division %d\n",ans);
    }
    return 0;
}