#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define N 1002

struct ban
{
    pair<string,int> t;
    int d;
};
bool operator<(const ban& a,const ban& b)
{
    if(a.d>b.d)
        return true;
    if(a.d<b.d)
        return false;
    return a.t.second<b.t.second;
}

int n,m;
pair<string,int> b[N];
vector<pair<string,int> > ans;

pair<string,int> s;
map<pair<string,int>,vector<pair<string,int> > > a;

void bfs()
{
    set<string> c;
    priority_queue<ban> q;
    ban t;
    t.t=s;
    t.d=0;
    q.push(t);
    while(1)
    {
        bool z=false;
        do
        {
            if(q.empty())
            {
                z=true;
                break;
            }
            t=q.top();
            q.pop();
        }while(c.find(t.t.first)!=c.end());
        if(z)
            break;
        c.insert(t.t.first);
        ans.push_back(t.t);
        for(int i=0;i<a[t.t].size();++i)
        {
            ban h;
            h.t=a[t.t][i];
            h.d=t.d+1;
            if(c.find(h.t.first)==c.end())
                q.push(h);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        pair<string,int> t;
        cin>>t.first>>t.second;
        b[i]=t;
        cin>>m;
        for(int j=0;j<m;++j)
        {
            pair<string,int> h;
            cin>>h.first>>h.second;
            a[t].push_back(h);
        }
    }
    s=b[1];
    bfs();
    sort(ans.begin(),ans.end());
    cout<<ans.size()-1<<endl;
    for(int i=0;i<ans.size();++i)
    {
        if(ans[i].first==s.first)
            continue;
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
    return 0;
}