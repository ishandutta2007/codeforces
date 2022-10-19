#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N=200002;

int n;
int b[N];
vector<int> a[N];

int c[N];
void dfs(int x,int g)
{
    c[x]=g;
    for(int i=0;i<a[x].size();++i)
    {
        int h=a[x][i];
        if(!c[h] && b[x]==b[h])
            dfs(h,g);
    }
}

vector<int> bfs(int x)
{
    queue<int> q;
    q.push(x);
    vector<int> d(n+1);
    d[x]=1;
    while(!q.empty())
    {
        x=q.front();
		q.pop();
        for(int i=0;i<a[x].size();++i)
        {
            int h=a[x][i];
            if(!d[h])
			{
                d[h]=d[x]+1;
				q.push(h);
			}
        }
    }
    return d;
}

int farest(int x)
{
    vector<int> d=bfs(x);
    int maxu=0,maxi;
    for(int i=1;i<=n;++i)
    {
        if(maxu<d[i])
        {
            maxu=d[i];
            maxi=i;
        }
    }
    return maxi;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>b[i];
    for(int i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int k=0;
    for(int i=1;i<=n;++i)
    {
        if(!c[i])
        {
            k++;
            dfs(i,k);
        }
    }
    vector<int> a2[N];
    for(int x=1;x<=n;++x)
    {
        for(int i=0;i<a[x].size();++i)
        {
            int y=a[x][i];
            if(c[x]!=c[y])
            {
                a2[c[x]].push_back(c[y]);
            }
        }
    }
    n=k;
    for(int i=1;i<=n;++i)
        a[i]=a2[i];
    int x1=farest(1);
    int x2=farest(x1);
    vector<int> d=bfs(x1);
    cout<<d[x2]/2<<endl;
    return 0;
}