#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;
struct ban
{
    int x;
    int d;
};
bool operator<(const ban& a,const ban& b)
{
    return a.d>b.d;
}

int n,m,s,l;
vector<ban> a[N];

int d[N];
bool c[N];
void djk()
{
    priority_queue<ban> q;
    ban t;
    t.x=s;
    t.d=0;
    q.push(t);
    while(1)
    {
        do
        {
            if(q.empty())
                return;
            t=q.top();
            q.pop();
        }while(c[t.x]);
        c[t.x]=true;
        d[t.x]=t.d;
        for(int i=0;i<a[t.x].size();++i)
        {
            ban h=a[t.x][i];
            h.d+=t.d;
            q.push(h);
        }
    }
}

pair<pair<int,int>,int> b[N];
int main()
{
    //freopen("span.in","r",stdin);
    cin>>n>>m>>s;
    for(int i=0;i<m;++i)
    {
        ban t;
        int x,y;
        cin>>x>>y>>t.d;
        t.x=y;
        a[x].push_back(t);
        t.x=x;
        a[y].push_back(t);
        b[i]=m_p(m_p(x,y),t.d);
    }
    cin>>l;
    djk();
    int ans=0;
    for(int x=1;x<=n;++x)
        if(d[x]==l)
            ans++;
    for(int i=0;i<m;++i)
    {
        int x=b[i].first.first,y=b[i].first.second,dd=b[i].second;
        int px=-1;
        int py=-1;
        if(d[x]<l && d[x]+dd>l)
        {
            px=l-d[x];
        }
        if(d[y]<l && d[y]+dd>l)
        {
            py=dd-(l-d[y]);
        }
        if(d[y]+(dd-px)<px+d[x])
            px=-1;
        if(d[x]+py<(dd-py)+d[y])
            py=-1;
        if((px<0 && py>0) || (px>0 && py<0))
            ++ans;
        if(px>0 && py>0)
        {
            if(px==py)
                ++ans;
            if(px<py)
                ans+=2;
        }
    }
    cout<<ans<<endl;
    return 0;
}