#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

int n,m,k;
set<int> c;
map<pair<int,int>,bool> b;

void dfs(int x)
{
    c.erase(x);
    int i=1;
    for(;;)
    {
        set<int>::iterator it=c.lower_bound(i);
        if(it==c.end())
            return;
        i=*it;
        if(b.find(m_p(x,i))==b.end() && b.find(m_p(i,x))==b.end())
            dfs(i);
        else
            ++i;
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
        c.insert(i);
    int z=0;
    for(int i=0;i<m;++i)
    {
        pair<int,int> t;
        cin>>t.first>>t.second;
        if(t.first==1 || t.second==1)
            ++z;
        b[t]=true;
    }
    dfs(1);
    if(c.empty())
    {
        int cc=0;
        for(int i=2;i<=n;++i)
            c.insert(i);
        for(int i=2;i<=n;++i)
        {
            if(c.find(i)!=c.end())
            {
                ++cc;
                dfs(i);
            }
        }
        if(cc<=k && k<=(n-1)-z)
            cout<<"possible"<<endl;
        else
            cout<<"impossible"<<endl;
    }
    else
        cout<<"impossible"<<endl;
    return 0;
}