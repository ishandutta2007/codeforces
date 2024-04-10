#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n;
string a[N];
map<int, int> m;

void reduce(string &s)
{
    stack<char> st;
    for(auto it:s)
    {
        if(it=='(')
            st.push(it);
        else
        {
            if(st.size() && st.top()=='(')
            {
                st.pop();
            }
            else
            {
                st.push(it);
            }
        }
    }
    s="";
    while(!st.empty())
    {
        s+=st.top();
        st.pop();
    }
    reverse(s.begin(), s.end());
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        reduce(a[i]);
        if(!a[i].size())
            m[0]++;
        else
        {
            set<char> cur;
            for(auto it:a[i])
            {
                cur.insert(it);
                if(cur.size()>1)
                    break;
            }
            if(cur.size()==1)
            {
                int len=a[i].size();
                if(a[i][0]=='(')
                    m[len]++;
                else
                    m[-len]++;
            }
        }
    }
    int ans=0;
    for(auto it:m)
    {
        if(it.first<0)
            continue;
        ans+=it.second * (m[-it.first]);
    }
    cout<<ans;
    return 0;
}