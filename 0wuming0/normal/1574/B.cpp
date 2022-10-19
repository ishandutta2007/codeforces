#include"bits/stdc++.h"
using namespace std;
char s[10005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,m;
        cin>>a>>b>>c>>m;
        int r=a+b+c-3;
        int l=max(a,b);
        l=max(l,c);
        l=2*l-1-a-b-c;
        l=max(l,0);
        if(l<=m&&m<=r)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}