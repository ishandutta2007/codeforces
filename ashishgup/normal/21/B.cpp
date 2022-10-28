#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int a1, b1, c1, a2, b2, c2;

int32_t main()
{
    IOS;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    if(a1==0 && b1==0 && c1!=0)
    {
        cout<<"0";
        return 0;
    }    
    if(a2==0 && b2==0 && c2!=0)
    {
        cout<<"0";
        return 0;
    }
    if(a1==0 && b1==0 && c1==0)
    {   
        cout<<"-1";
        return 0;
    }  
    if(a2==0 && b2==0 && c2==0)
    {   
        cout<<"-1";
        return 0;
    }      
    int den=a1*b2 - b1*a2;
    if(den==0)
    {
        int x=c1*b2 - c2*b1;
        int y=a1*c2 - c1*a2;
        if(x==0 && y==0)
            cout<<"-1";
        else
            cout<<"0";
    }
    else
    {
        cout<<"1";
    }
}