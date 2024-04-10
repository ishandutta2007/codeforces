#include"bits/stdc++.h"
using namespace std;
int a[105],b[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        int aa=0,bb=0;
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            if(a[i]>b[i])swap(a[i],b[i]);
            aa=max(aa,a[i]);
            bb=max(bb,b[i]);
        }
        cout<<aa*bb<<endl;
    }
    return 0;
}