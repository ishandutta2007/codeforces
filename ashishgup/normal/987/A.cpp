#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

map<string, string> m;

int32_t main()
{
    IOS;
    m["purple"]="Power";
    m["green"]="Time";
    m["blue"]="Space";
    m["orange"]="Soul";
    m["red"]="Reality";
    m["yellow"]="Mind";
    set<string> s;
    for(auto it:m)
        s.insert(it.first);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        s.erase(str);
    }
    cout<<s.size()<<endl;
    for(auto it:s)
        cout<<m[it]<<endl;
    return 0;
}