#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int l,r;
        cin>>l>>r;
        if(r>=l*2)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}