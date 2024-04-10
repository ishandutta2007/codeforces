#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k1,k2;
        int w,b;
        cin>>n>>k1>>k2;
        cin>>w>>b;
        if(k1>k2)swap(k1,k2);
        int x=k1+(k2-k1)/2;
        k1=n-k1;
        k2=n-k2;
        if(k1>k2)swap(k1,k2);
        int y=k1+(k2-k1)/2;
        if(x>=w&&y>=b)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}