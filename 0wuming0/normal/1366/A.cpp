#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a<b)swap(a,b);
        if(a>=2*b)cout<<b<<endl;
        else cout<<(a-b)+(b-(a-b))*2/3<<endl;
    }
    return 0;
}