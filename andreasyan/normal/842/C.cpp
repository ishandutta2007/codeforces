#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=2*100005;
struct ban
{
    int x,y;
};

int a[N];
int n;
int an[N];
vector<int> g[N];
vector<ban> v;
int gcd(int x,int y)
{
    if(x==0)
        return y;
    if(x>y)
        return gcd(y,x);
    return gcd(y%x,x);
}
void dfs(int x,int p,int y,int d)
{
    if(p==-1)
    {
        an[1]=a[x];
    }
    else
    {
        int ans=0;
        for(int i=0;i<v.size();++i)
        {
            if(a[x]%v[i].y==0)
                ++v[i].x;
            if(v[i].x>=d-1)
            {
                ans=v[i].y;
            }
        }
        an[x]=max(ans,y);
    }
    for(int i=0;i<g[x].size();++i)
    {
        int h=g[x][i];
        if(h!=p)
        {
            dfs(h,x,gcd(y,a[h]),d+1);
        }
    }
    for(int i=v.size()-1;i>=0;--i)
    {
        if(a[x]%v[i].y==0)
            --v[i].x;
    }
}
int main()
{
    //input
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ///////
    for(int i=1;i<=a[1];++i)
    {
        if(a[1]%i==0)
        {
            ban t;
            t.y=i;
            t.x=0;
            v.push_back(t);
        }
    }
    ///////
    dfs(1,-1,0,0);
    ///////
    for(int i=1;i<=n;++i)
        printf("%d ",an[i]);
    return 0;
}