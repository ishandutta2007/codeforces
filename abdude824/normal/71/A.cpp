#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        if(s.size()<=10)
            cout<<s<<endl;
        else
        {
            cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
        }
    }
}