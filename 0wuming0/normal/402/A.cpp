#include"bits/stdc++.h"
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int p=(b-1)/d+1;
    cout<<max((p-1)/a+1,p-c)<<endl;
    return 0;
}