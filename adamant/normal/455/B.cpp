#include <bits/stdc++.h>

using namespace std;

const int INF=1e9;
const int maxn=1e5+100;

struct trie
{
    struct node
    {
        map<char,int> to;
        bool win;
        bool not_win;
    }v[maxn];
    int sz=1;

    void add_str(string &s)
    {
        int x=0;
        for(int i=0;i<s.size();i++)
        {
            if(v[x].to[s[i]]) x=v[x].to[s[i]];
            else x=v[x].to[s[i]]=sz++;
        }
    }

    void dfs(int x)
    {
        v[x].win=0;
        v[x].not_win=v[x].to.empty();
        for(auto it:v[x].to)
        {
            dfs(it.second);
            v[x].win|=!v[it.second].win;
            v[x].not_win|=!v[it.second].not_win;
        }
    }

    void solve()
    {
        dfs(0);
    }
}me;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif
    int n,k;
    cin>>n>>k;
    while(n--)
    {
        string s;
        cin>>s;
        me.add_str(s);
    }
    me.solve();
    int w=me.v[0].win;
    int nw=me.v[0].not_win;
    if(!w) cout<<"Second"<<endl;
    if(w && nw) cout<<"First"<<endl;
    if(w && !nw) cout<<((k&1)?"First":"Second")<<endl;

}