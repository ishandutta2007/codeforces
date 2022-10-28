#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    string s="";
    while(n>=2)
    {
        s+='8';
        n-=2;
    }
    if(n)
        s+='6';
    if(s.size()<=18)
        cout<<s;
    else
        cout<<"-1";
    return 0;
}