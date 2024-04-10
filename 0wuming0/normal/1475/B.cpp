#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a=n/2020,b=n%2020;
        if(a>=b)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}