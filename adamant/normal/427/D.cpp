#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

struct suffix_automaton
{
    struct state
    {
        int len=0,link=-1;
        int f=0,s=0;
        map<char,int> to;
    } st[20000];
    int last=0,sz=1;

    void add_letter(char c)
    {
        int cur=sz++;
        int p=last;
        last=cur;
        st[cur].len=st[p].len+1;
        for(;p!=-1 && !st[p].to[c];p=st[p].link) st[p].to[c]=cur;
        if(p==-1)
        {
            st[cur].link=0;
            return;
        }
        int q=st[p].to[c];
        if(st[q].len==st[p].len+1)
        {
            st[cur].link=q;
            return;
        }
        int cl=sz++;
        st[cl]=st[q];
        st[cl].len=st[p].len+1;
        st[cur].link=st[q].link=cl;
        for(;p!=-1 && st[p].to[c]==q;p=st[p].link) st[p].to[c]=cl;
    }

    vector<int> used;

    void dfs(int x)
    {
        used[x]=1;
        for(auto it:st[x].to)
        {
            if(!used[it.second]) dfs(it.second);
            if(it.first=='#') st[x].f++;
            else if(it.first=='$') st[x].s++;
            else st[x].f+=st[it.second].f,
                 st[x].s+=st[it.second].s;
        }
    }

    int build(string s)
    {
        for(int i=0;i<s.size();i++) add_letter(s[i]);
        used.assign(sz,0);
        dfs(0);
        int ans=sz;
        for(int i=1;i<sz;i++) if(st[i].f==1 && st[i].s==1) ans=min(ans,st[st[i].link].len+1);
        return ans==sz?-1:ans;
    }
} me;

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin>>a>>b;
    cout<<me.build(a+'#'+b+'$')<<endl;
}