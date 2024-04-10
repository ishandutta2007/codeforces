#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

struct suffix_automaton
{
    struct state
    {
        int len=0,link=-1;
        map<char,int> to;

        int cnt=0;
        vector<int> rev_link;
    } st[2000000];
    int last=0,sz=1;
    void add_letter(char c)
    {
        int cur=sz++;
        int p=last;
        last=cur;
        for(;p!=-1 && !st[p].to[c];p=st[p].link) st[p].to[c]=cur;
        if(p==-1)
        {
            st[cur].link=0;
            return;
        }
        else
        {
            int q=st[p].to[c];
            if(st[q].len==st[p].len+1)
            {
                st[cur].link=q;
                return;
            }
            else
            {
                int cl=sz++;
                st[cl]=st[q];
                st[cl].len=st[p].len+1;
                st[q].link=st[cur].link=cl;
                for(;p!=-1 && st[p].to[c]==q;p=st[p].link) st[p].to[c]=cl;
            }
        }
    }
vector<int> used;
    void build(string s)
    {
        for(int i=0;i<s.size();i++) add_letter(s[i]);
for(int p=last;p!=-1;p=st[p].link) st[p].cnt=1;
used.assign(sz,0);
        cnt_upd(0);
    }

    void cnt_upd(int x)
    {
used[x]=1;
        for(auto it:st[x].to)
        {
            if(!used[it.second]) cnt_upd(it.second);
            st[x].cnt+=st[it.second].cnt;
        }
    }

    int check(string s)
    {
        int n=s.size();
        s+=s;
        unordered_map<int,int> used;
        int c_ln=0;
        int c_st=0;
        int ret=0;
        for(int i=0;i<2*n;i++)
        {
            while(c_st!=-1 && !st[c_st].to[s[i]]) c_st=st[c_st].link,c_ln=st[c_st].len;
            if(c_st==-1) c_st=0,c_ln=0;
            else c_st=st[c_st].to[s[i]],c_ln++;
            if(c_ln==n)
            {
                if(used[c_st]) break;
ret+=st[c_st].cnt;
                used[c_st]=1;
                c_ln--;
                if(c_ln==st[st[c_st].link].len) c_st=st[c_st].link;
            }
        }
        return ret;
    }
} me;

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    me.build(s);
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s;
        cout<<me.check(s)<<"\n";
    }
}