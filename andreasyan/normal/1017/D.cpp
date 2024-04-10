#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=13;
struct ban
{
    int x;
    int sum;
};
bool operator<(const ban& a,const ban& b)
{
    return a.sum<b.sum;
}

int n,q,m;
int g[N];

int b[1<<N];

vector<ban> v;

int ans[1<<N][102];
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("search.in","r",stdin);
    //freopen("search.out","w",stdout);
    cin>>n>>m>>q;
    for(int i=0;i<n;++i)
        cin>>g[i];
    for(int i=0;i<m;++i)
    {
        char a[N];
        cin>>a;
        int x=0;
        for(int j=0;j<n;++j)
        {
            if(a[j]=='1')
                x+=(1<<j);
        }
        b[x]++;
    }
    for(int x=0;x<(1<<n);++x)
    {
        ban t;
        t.x=x;
        t.sum=0;
        for(int i=0;i<n;++i)
        {
            if((x&(1<<i)))
            {
                t.sum+=g[i];
            }
        }
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i)
    {
        int y=0;
        for(int j=0;j<n;++j)
        {
            if(!(v[i].x&(1<<j)))
            {
                y+=(1<<j);
            }
        }
        int j=0;
        int yans=0;
        for(int k=0;k<=100;++k)
        {
            while(1)
            {
                if(j==v.size())
                    break;
                if(v[j].sum<=k)
                {
                    yans+=b[y^v[j].x];
                    ++j;
                }
                else
                    break;
            }
            ans[v[i].x][k]=yans;
        }
    }
    while(q--)
    {
        char a[N];
        cin>>a;
        int x=0;
        for(int j=0;j<n;++j)
        {
            if(a[j]=='1')
                x+=(1<<j);
        }
        int k;
        cin>>k;
        cout<<ans[x][k]<<endl;
    }
    return 0;
}