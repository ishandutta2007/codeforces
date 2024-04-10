#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int d=pow(10,a-1)+0.5;
        int e=pow(10,b-1)+0.5;
        int f=pow(10,c-1)+0.5;
        if(a>b)cout<<d+f<<" "<<e<<endl;
        else cout<<d<<" "<<e+f<<endl;
    }
    return 0;
}