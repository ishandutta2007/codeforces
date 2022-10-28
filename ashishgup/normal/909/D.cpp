#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int pre[N], nxt[N];
char s[N];
set<int> active;

void update(int idx)
{
    if(idx<=0 || idx>n)
        return;
    if(active.find(idx)!=active.end())
        active.erase(idx);
    if(pre[idx]!=0 && s[idx]!=s[pre[idx]])
        active.insert(idx);
    if(nxt[idx]!=n+1 && s[idx]!=s[nxt[idx]])
        active.insert(idx);
}

int32_t main()
{
    IOS;
    string str;
    cin>>str;
    n=str.size();
    for(int i=1;i<=n;i++)
    {
        s[i]=str[i-1];
        pre[i]=i-1;
        nxt[i]=i+1;
    }
    for(int i=1;i<=n;i++)
    {
        if(i>=2 && s[i]!=s[i-1])
            active.insert(i);
        if(i<=n-1 && s[i]!=s[i+1])
            active.insert(i);
    }
    for(int ops=0;ops<=n;ops++)
    {
        if(!active.size())
        {
            cout<<ops;
            return 0;
        }
        vector<int> v;
        for(auto it:active)
        {
            v.push_back(it);
        }
        for(auto it:v)
        {
            int idx=it;
            active.erase(idx);
            int prev=pre[idx];
            int next=nxt[idx];
            pre[next]=prev;
            nxt[prev]=next;
            update(prev);
            update(next);
        }
    }
    return 0;
}