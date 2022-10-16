#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>

using namespace std;

#define NMAX 100005
int tata[NMAX];
int h[NMAX];
int din[NMAX];

int f(int x)
{
    if(x!=tata[x])
        tata[x]=f(tata[x]);
    return tata[x];
}

inline void uneste(int x,int y)
{
    x=f(x);
    y=f(y);

    if(x==y)
        return;

    if(h[x]>h[y])
    {
        tata[y]=x;
        din[x]+=din[y];
    }
    else
    {
        if(h[x]==h[y])
            h[y]++;
        tata[x]=y;
        din[y]+=din[x];
    }
}

int val[NMAX];
bitset<NMAX> viz;
vector<pair<int,int> > v;
vector<int> graf[NMAX];

int main()
{
    int n,m,i;
    cin>>n>>m;

    for(i=1;i<=n;i++)
    {
        tata[i]=i;
        h[i]=1;
        din[i]=1;

        cin>>val[i];
        v.push_back(make_pair(-val[i],i));
    }
    sort(v.begin(),v.end());

    int a,b;
    while(m--)
    {
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    int nod,cat;

    vector<pair<int,int> >::iterator it;
    vector<int>::iterator it2;

    double rez=0;

    for(it=v.begin();it!=v.end();it++)
    {
        nod=it->second;
        cat=-(it->first);

        viz[nod]=1;

        long long int s=0,sp=0;
        for(it2=graf[nod].begin();it2!=graf[nod].end();it2++)
            if(viz[*it2])
            {
                if(f(nod)!=f(*it2))
                {
                    s+=din[f(*it2)];
                    sp+=(1ll*din[f(*it2)]*din[f(*it2)]);

                    uneste(nod,*it2);
                }
            }
        rez+=(cat*((s+((s*s-sp)/2))/(1.0*n*(n-1))));
    }

    cout<<fixed<<setprecision(6)<<(2.0*rez)<<'\n';
    return 0;
}