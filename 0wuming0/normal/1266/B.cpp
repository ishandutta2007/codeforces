#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        if(!(n%14<=6&&1<=n%14))cout<<"NO"<<endl;
        else if(n<=14)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}