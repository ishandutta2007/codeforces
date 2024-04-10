#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;

int n,m;
vector<int> a[N],b[N];
int s;

int cc[N];
bool dfs(int x)
{
    cc[x]=1;
    for(int i=0;i<a[x].size();++i)
    {
        int h=a[x][i];
        if(cc[h]==1)
            return true;
        if(cc[h]==0)
            if(dfs(h))
                return true;
    }
    cc[x]=2;
    return false;
}

bool c[N][2];
int p[N][2];
int main()
{
    cin>>n>>m;
    for(int x=1;x<=n;++x)
    {
        int mm;
        cin>>mm;
        while(mm--)
        {
            int y;
            cin>>y;
            a[x].push_back(y);
            b[y].push_back(x);
        }
    }
    cin>>s;
    queue<pair<int,int> > q;
    for(int x=1;x<=n;++x)
        if(a[x].empty())
        {
            c[x][0]=true;
            q.push(m_p(x,0));
        }
    while(!q.empty())
    {
        pair<int,int> t=q.front();
        q.pop();
        int x=t.first;
        int z=t.second;
        for(int i=0;i<b[x].size();++i)
        {
            int h=b[x][i];
            if(!c[h][z^1])
            {
                c[h][z^1]=true;
                p[h][z^1]=x;
                q.push(m_p(h,z^1));
            }
        }
    }
    if(c[s][1])
    {
        cout<<"Win"<<endl;
        int x=s,z=1;
        while(1)
        {
            cout<<x<<' ';
            if(a[x].empty())
                break;
            x=p[x][z];
            z^=1;
        }
        cout<<endl;
    }
    else
    {
        if(dfs(s))
            cout<<"Draw"<<endl;
        else
            cout<<"Lose"<<endl;
    }
    return 0;
}