#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n;
int a[N], ans[N], l[N], r[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    stack<int> st;
    for(int i=1;i<=n;i++)
    {
        while(!st.empty() && a[st.top()]>a[i])
        {
            r[st.top()]=i-1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        r[st.top()]=n;
        st.pop();
    }
    for(int i=n;i>=1;i--)
    {
        while(!st.empty() && a[st.top()]>a[i])
        {
            l[st.top()]=i+1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        l[st.top()]=1;
        st.pop();
    }
    for(int i=1;i<=n;i++)
    {
        int len=r[i]-l[i]+1;
        ans[len]=max(ans[len], a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        ans[i]=max(ans[i+1], ans[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
}