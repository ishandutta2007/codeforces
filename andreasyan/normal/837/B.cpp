#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=102;

int n,m;
char a[N][N];

bool stg1()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            if(a[i][j]!=a[i][0])
                return false;
    }
    bool r=false,g=false,b=false;
    for(int i=0;i<n;++i)
    {
        if(a[i][0]=='R')
            r=true;
        if(a[i][0]=='G')
            g=true;
        if(a[i][0]=='B')
            b=true;
    }
    if(!r || !g || !b)
        return false;
    vector<int> p;
    for(int i=0;i<n;++i)
    {
        if(!i || a[i][0]!=a[i-1][0])
            p.push_back(i);
    }
    if(p.size()!=3)
        return false;
    return ((p[1]-p[0]==p[2]-p[1] && p[1]-p[0]==n-p[2]));
}

bool stg2()
{
    for(int j=0;j<m;++j)
    {
        for(int i=0;i<n;++i)
            if(a[0][j]!=a[i][j])
                return false;
    }
    bool r=false,g=false,b=false;
    for(int j=0;j<m;++j)
    {
        if(a[0][j]=='R')
            r=true;
        if(a[0][j]=='G')
            g=true;
        if(a[0][j]=='B')
            b=true;
    }
    if(!r || !g || !b)
        return false;
    vector<int> p;
    for(int j=0;j<m;++j)
    {
        if(!j || a[0][j]!=a[0][j-1])
            p.push_back(j);
    }
    if(p.size()!=3)
        return false;
    return ((p[1]-p[0]==p[2]-p[1] && p[1]-p[0]==m-p[2]));
}

bool stg()
{
    if(stg1())
        return true;
    if(stg2())
        return true;
    return false;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    if(stg())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}