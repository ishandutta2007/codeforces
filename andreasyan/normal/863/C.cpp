#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int n=3;

long long k;
int sa,sb;
int a[n+1][n+1],b[n+1][n+1];

vector<pair<int,int> > v;
bool c[n+1][n+1];
void dfs(int x,int y)
{
    c[x][y]=true;
    v.push_back(m_p(x,y));
    if(c[a[x][y]][b[x][y]])
        return;
    dfs(a[x][y],b[x][y]);
}

long long pa[n*n*n*n],pb[n*n*n*n];

long long suma(int l,int r)
{
    if(l>r)
        return 0;
    if(!l)
        return pa[r];
    return pa[r]-pa[l-1];
}

long long sumb(int l,int r)
{
    if(l>r)
        return 0;
    if(!l)
        return pb[r];
    return pb[r]-pb[l-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>k>>sa>>sb;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            cin>>b[i][j];
    }
    dfs(sa,sb);
    for(int i=0;i<v.size();++i)
    {
        if(i)
        {
            pa[i]=pa[i-1];
            pb[i]=pb[i-1];
        }
        if(v[i].first==v[i].second)
            continue;
        if((v[i].first==2 && v[i].second==1) || (v[i].first==3 && v[i].second==2) || (v[i].first==1 && v[i].second==3))
            ++pa[i];
        else
            ++pb[i];
    }
    int j;
    for(int i=0;i<v.size();++i)
    {
        if(v[i]==m_p(a[v.back().first][v.back().second],b[v.back().first][v.back().second]))
        {
            j=i;
            break;
        }
    }
    if(k-1<j)
    {
        cout<<suma(0,k-1)<<' '<<sumb(0,k-1)<<endl;
        return 0;
    }
    long long ansa=0,ansb=0;
    ansa+=suma(0,j-1);
    ansb+=sumb(0,j-1);
    k-=j;
    ansa+=((k/(v.size()-j))*suma(j,v.size()-1));
    ansb+=((k/(v.size()-j))*sumb(j,v.size()-1));
    ansa+=(suma(j,j+(k%(v.size()-j))-1));
    ansb+=(sumb(j,j+(k%(v.size()-j))-1));
    cout<<ansa<<' '<<ansb<<endl;
    return 0;
}