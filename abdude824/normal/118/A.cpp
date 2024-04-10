#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    string s;cin>>s;
    string v="aioueyAIOUEY";
    for(int i=0;i<s.size();i++)
    {
        if(find(v.begin(),v.end(), s[i])!=v.end())
            continue;
        else{
            s[i]=tolower(int(s[i]));
            cout<<"."<<s[i];
        }
    }
}