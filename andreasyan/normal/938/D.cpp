#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct ban
{
    int x;
    long long d;
};
bool operator<(const ban& a,const ban& b)
{
    return a.d>b.d;
}
const int N=200005;

int n,m;
vector<ban> a[N];
bool c[N];
long long g[N], ans[N];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y;
        long long d;
        cin>>x>>y>>d;
        d*=2;
        ban t;
        t.d=d;
        t.x=y;
        a[x].push_back(t);
        t.x=x;
        a[y].push_back(t);
    }
    priority_queue<ban> q;
    for(int i=1;i<=n;++i)
    {
        cin>>g[i];
        ban t;
        t.x=i;
        t.d=g[i];
        q.push(t);
    }
    while(1)
    {
        ban t;
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
        }while(c[t.x]);
        if(z)
            break;
        c[t.x]=true;
        ans[t.x]=t.d;
        for(int i=0;i<a[t.x].size();++i)
        {
            ban h=a[t.x][i];
            h.d+=t.d;
            q.push(h);
        }
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}