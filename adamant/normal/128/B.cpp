#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

struct suffix_automaton
{
   struct state
   {
       int len=0,link=-1;
       map<char,int> to;
       long long cnt1=0,cnt2=0;
   } st[160000];
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

   void build(string &s)
   {
       for(int i=0;i<s.size();i++) add_letter(s[i]);
       used.assign(sz,0);
       dfs(0);
   }

   vector<int> used;

   void dfs(int x)
   {
       used[x]=1;
       for(auto it:st[x].to)
       {
           if(!used[it.second]) dfs(it.second);
           if(it.first=='#') st[x].cnt1++;
           else st[x].cnt1+=st[it.second].cnt1;
           st[x].cnt2+=st[it.second].cnt2;
       }
       st[x].cnt2+=st[x].cnt1;
   }

   void order(int cur,int k,string &ans,int x)
   {

       if(cur>=k) return;
       for(auto it=st[x].to.begin();it!=st[x].to.end();it++)
       {

           if(cur+st[it->second].cnt2>=k)
           {
               cur+=st[it->second].cnt1;
               ans+=it->first;
               order(cur,k,ans,it->second);
               return;
           }
           else
               cur+=st[it->second].cnt2;
       }
       ans="No such line.";
   }

   string order(int k)
   {
       string ret;
       order(0,k,ret,0);
       return ret;
   }

}me;

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    s+='#';
    int k;
    cin>>k;
    me.build(s);
    cout<<me.order(k)<<endl;
}