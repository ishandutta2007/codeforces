#include"bits/stdc++.h"
using namespace std;
int main()
{
    int a=5000000,n;
    cin>>n;
    for(int i=n;i>0;i--)
    {
        cout<<a-i<<" \n"[i==1];
    }
}