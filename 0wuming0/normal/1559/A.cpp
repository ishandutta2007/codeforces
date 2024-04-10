#include"bits/stdc++.h"
using namespace std;
int a[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            a[0]&=a[i];
        }
        cout<<a[0]<<endl;
    }
    return 0;
}