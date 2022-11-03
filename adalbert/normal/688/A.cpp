#include <bits/stdc++.h>

using namespace std;
long long n,ans,d,mx;
string s,st;
int main()
{
    cin>>n>>d;
    for (int i=1;i<=n;i++)
    s+='1';
    for (int i=1;i<=d;i++)
    {
        cin>>st;
             if (st!=s) ans++; else ans=0;
             mx=max(ans,mx);
    }
    cout<<mx;

}