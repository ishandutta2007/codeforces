#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int32_t main()
{
    IOS;
    string s;
    cin>>s;
    string str=s;
    reverse(str.begin(), str.end());
    s+=str;
    cout<<s;
    return 0;
}