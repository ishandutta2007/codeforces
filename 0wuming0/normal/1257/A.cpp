#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(c>d)swap(c,d);
        cout<<min(d-c+b,a-1)<<endl;
    }
    return 0;
}