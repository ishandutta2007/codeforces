#include"bits/stdc++.h"
using namespace std;
int h1,a1,c1,h2,a2;
int main()
{
    cin>>h1>>a1>>c1>>h2>>a2;
    c1-=a2;
    int t=(h2-1)/a1+1;
    int h=(t-1)*a2;
    if(h1>h)
    {
        cout<<t<<endl;
        while(t--)cout<<"STRIKE"<<endl;
    }
    else
    {
        int p=h-h1+1;
        int q=(p-1)/c1+1;
        cout<<t+q<<endl;
        while(q--)cout<<"HEAL"<<endl;
        while(t--)cout<<"STRIKE"<<endl;
    }
    return 0;
}