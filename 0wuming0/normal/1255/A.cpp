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
        int c=abs(a-b);
        cout<<c/5+(c%5+1)/2<<endl;
    }
    return 0;
}