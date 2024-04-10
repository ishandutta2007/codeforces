#include <iostream>
#include <algorithm>

using namespace std;

class punct
{
public:
    int x,y;

    punct(int a,int b)
    {
        x=a;
        y=b;
    }

    punct()
    {
        x=0;
        y=0;
    }
};

punct rot(punct a,int n,int m,int cate)
{
    if(cate==0)
        return a;
    if(cate==1)
        return punct(a.y,n-a.x+1);
    return rot(punct(a.y,n-a.x+1),m,n,cate-1);
}

punct sim(punct a,int n,int m)
{
    return punct(a.x,m-a.y+1);
}

int main()
{
    int n,m,x,y,z,p,i;
    cin>>n>>m>>x>>y>>z>>p;

    x%=4;
    y%=2;
    z%=4;
    z=(4-z)%4;

    for(i=0;i<p;i++)
    {
        punct u;
        cin>>u.x>>u.y;

        u=rot(u,n,m,x);

        int nn=n,mn=m;

        if(x%2==1)
            swap(nn,mn);

        if(y)
        u=sim(u,nn,mn);
        u=rot(u,nn,mn,z);

        cout<<u.x<<' '<<u.y<<'\n';
    }

    return 0;
}