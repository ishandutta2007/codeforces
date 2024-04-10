#include <iostream>
using namespace std;
const int N=505;

int n,m;
int a[N][N];

int c[N],p[N];
int s,e;
bool dfs(int x)
{
    c[x]=1;
    for(int h=1;h<=n;++h)
        if(a[x][h])
        {
            if(c[h]==1)
            {
                s=h;
                e=x;
                return true;
            }
            if(c[h]==0)
            {
                p[h]=x;
                if(dfs(h))
                    return true;
            }
        }
    c[x]=2;
    return false;
}
bool stg()
{
    for(int i=1;i<=n;++i)
        c[i]=0;
    for(int i=1;i<=n;++i)
        if(!c[i])
        {
            if(dfs(i))
                return true;
        }
    return false;
}

int main()
{
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
    }
    if(stg())
    {
        int ee=e;
        int ss=s;
        int pp[N];
        for(int i=1;i<=n;++i)
            pp[i]=p[i];
        a[ee][ss]=0;
        if(!stg())
        {
            cout<<"YES"<<endl;
            return 0;
        }
        a[ee][ss]=1;
        for(int y=ee;y!=ss;y=pp[y])
        {
            int x=pp[y];
            a[x][y]=0;
            if(!stg())
            {
                cout<<"YES"<<endl;
                return 0;
            }
            a[x][y]=1;
        }
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
    return 0;
}