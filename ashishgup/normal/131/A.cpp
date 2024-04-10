#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    string s;
    cin>>s;
    bool check=1;
    for(int i=1;i<s.size();i++)
        check&=(s[i]>='A' && s[i]<='Z');
    if(check)
    {
        for(auto &it:s)
        {
            if(isupper(it))
                it=tolower(it);
            else
                it=toupper(it);
        }
    }
    cout<<s;
    return 0;
}