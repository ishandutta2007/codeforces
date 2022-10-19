#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        if(a<4){cout<<4-a<<endl;continue;}
        if(a%2)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}