#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>

using namespace std;

struct muchie
{
    int a,b;
    int cost;

    muchie(int x,int y,int z)
    {
        a=x;
        b=y;
        cost=z;
    }
};

bool operator<(const muchie &a,const muchie &b)
{
    return (a.cost<b.cost);
}

char v[1005][15][15];
vector<muchie> toate;
//int dif[1005][1005];

int n,m,k,w;
inline void prec()
{
    int i,j,x=0,p,l;
    for(i=1;i<=k;i++)
    {
        for(j=i+1;j<=k;j++)
        {
            x=0;
            for(p=1;p<=n;p++)
                for(l=1;l<=m;l++)
                    x+=(v[i][p][l]!=v[j][p][l]);

            //dif[i][j]=dif[j][i]=(x*w);
            toate.push_back(muchie(i,j,x*w));
            //cout<<"muchie "<<i<<' '<<j<<' '<<x*w<<endl;
        }
    }
}

int tata[1005];
int h[1005];
bitset<1005> viz;

int f(int x)
{
    if(x!=tata[x])
        tata[x]=f(tata[x]);
    return tata[x];
}

inline bool uneste(int a,int b)
{
    a=f(a);
    b=f(b);

    if(a==b)
        return 0;

    if(h[a]>h[b])
        tata[b]=a;
    else
    {
        if(h[a]==h[b])
            h[b]++;
        tata[a]=b;
    }
    return 1;
}

int cn[1005];
vector<int> graf[1005];

void dfs(int nod)
{
    if(nod)
        cout<<nod<<' '<<cn[nod]<<'\n';

    vector<int>::iterator it;
    for(it=graf[nod].begin();it!=graf[nod].end();it++)
        if(!viz[*it])
        {
            viz[*it]=1;
            cn[*it]=nod;
            dfs(*it);
        }
}

int main()
{
    cin>>n>>m>>k>>w;

    int i,j;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin.get();
            cin.get(v[i][j]+1,1005);
        }
    }

    prec();
    h[0]=1;

    for(i=1;i<=k;i++)
    {
        h[i]=1;
        tata[i]=i;
        toate.push_back(muchie(0,i,n*m));
    }

    sort(toate.begin(),toate.end());
    vector<muchie>::iterator it;

    int tot=0;
    for(it=toate.begin();it!=toate.end();it++)
    {
        if(uneste(it->a,it->b))
        {
            tot+=(it->cost);
            graf[it->a].push_back(it->b);
            graf[it->b].push_back(it->a);
        }
    }

    cout<<tot<<'\n';

    for(i=0;i<=k;i++)
        if(!viz[i])
        {
            viz[i]=1;
            dfs(i);
        }

    return 0;
}