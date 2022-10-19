#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<string,string>mp;
    set<string>st;
    mp["purple"]="Power";st.insert("Power");
    mp["green"]="Time";st.insert("Time");
    mp["blue"]="Space";st.insert("Space");
    mp["orange"]="Soul";st.insert("Soul");
    mp["red"]="Reality";st.insert("Reality");
    mp["yellow"]="Mind";st.insert("Mind");
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        st.erase(mp[s]);
    }
    cout<<st.size()<<endl;
    for(auto s:st)
    {
        cout<<s<<endl;
    }
    return 0;
}