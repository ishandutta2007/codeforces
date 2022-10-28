#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
    IOS;
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n-2;i++)
    {
        set<char> st;
        for(int j=i;j<=i+2;j++)
        {
            st.insert(s[j]);
        }
        if(st.find('.')==st.end() && st.size()==3)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}