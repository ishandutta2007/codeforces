#include <bits/stdc++.h>

using namespace std;

#define TASK "test"
#define int long long
const int MOD=1000000007;

vector<int> ans;
struct suffix_automaton
{
    struct state
    {
        int len, link,l,r,f_len;
        map<char,int> to;

        state():len(0),link(-1),l(-1),r(-1){}
    };
    vector<state> st;
    int last,n;

    suffix_automaton():st(1),last(0){}

    void add(char c)
    {
        st.push_back(state());
        int cur=st.size()-1;
        st[cur].len=st[last].len+1;

        int p=last;
        for(; p+1 && !st[p].to[c]; p=st[p].link) st[p].to[c]=cur;
        if(p==-1) st[cur].link=0;
        else
        {
            int q=st[p].to[c];
            if(st[q].len==st[p].len+1) st[cur].link=q;
            else
            {
                st.push_back(st[q]);
                int cl=st.size()-1;
                st[cl].len=st[p].len+1;
                for(; p+1 && st[p].to[c]==q; p=st[p].link) st[p].to[c]=cl;
                st[cur].link=st[q].link=cl;
            }
        }
        last=cur;
    }

    void build(string s)
    {
        n=s.size();
        st.reserve(2*n);
        for(char it:s) add(it);
    }

    vector<int> f,s,t;
    vector<int> used;

    void dfs(int x)
    {
        used[x]=1;
        for(auto i:st[x].to)
        {
            if(!used[i.second]) dfs(i.second);
            if(i.first=='#') f[x]++;
            else if(i.first=='$') s[x]++;
            else if(i.first=='%') t[x]++;
            else
            {
                f[x]+=f[i.second];
                s[x]+=s[i.second];
                t[x]+=t[i.second];
            }
        }
    }

    void solve()
    {
        f.assign(st.size(),0);
        s.assign(st.size(),0);
        t.assign(st.size(),0);
        used.assign(st.size(),0);

        dfs(0);

        for(int i=0;i<st.size();i++)
        {
            if(!(st[i].len && st[i].len<=ans.size())) continue;
            ans[st[i].len-1]=(ans[st[i].len-1]+(f[i]*s[i]*t[i])%MOD)%MOD;
            if(!st[i].link) continue;
            ans[st[st[i].link].len-1]=(ans[st[st[i].link].len-1]-(f[i]*s[i]*t[i])%MOD+3*MOD)%MOD;
        }
    }
} me;

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b,c,x;
    cin>>a>>b>>c;
    x=a+'#'+b+'$'+c+'%';
    int n=a.size(),m=b.size(),k=c.size();
    int sz=min(n,min(m,k));
    ans.assign(sz,0);
    me.build(x);
    me.solve();
    for(int i=sz-2;i>=0;i--) ans[i]=(ans[i]+ans[i+1]+MOD)%MOD;
    for(int i=0;i<sz;i++) cout<<ans[i]<<' ';
 }