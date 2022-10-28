#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(false);
using namespace std;

int main()
{
    IOS
    ll t,s,x;
    cin>>t>>s>>x;
    bool check=false;
    if(x==t)
    {
        check=true;
    }
    if(x==t+1)
    {
        cout<<"NO";
        return 0;
    }
    ll check1=x-t;
    if(check1<0)
    {
        cout<<"NO";
        return 0;
    }
    if(check1%s==0)
    {
        check=true;
    }
    if((check1-1)%s==0)
    {
        check=true;
    }
    if(check)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}