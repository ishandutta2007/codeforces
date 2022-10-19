#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int r=sqrt(n);
        cout<<r-1+ceil((n-r+0.0)/r)<<endl;
    }
    return 0;
}