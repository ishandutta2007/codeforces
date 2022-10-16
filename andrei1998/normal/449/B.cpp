#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <bitset>

#define NMAX 100005
#define inf 500005000000000ll
using namespace std;

struct elem
{
    int nod;
    long long int val;
    int tip;

    elem(int a=0,long long int b=0,int c=0): nod(a),val(b),tip(c) {}
};

bool operator<(const elem &a,const elem &b)
{
    if(a.val==b.val)
        return (a.tip>b.tip);
    return a.val>b.val;
}

vector<elem> graf[NMAX];

long long int dist[NMAX];
bitset<NMAX> viz;
priority_queue<elem> coada;
int n,m,k;
int cate;

inline void dijkstra()
{
    for(int i=2;i<=n;i++)
        dist[i]=inf;

    coada.push(elem(1,0,0));

    elem y;
    while(!coada.empty())
    {
        y=coada.top();
        coada.pop();

        //cout<<"se scoate din coada "<<y.nod<<' '<<y.val<<' '<<y.tip<<endl;

        if(!viz[y.nod])
        {
            viz[y.nod]=1;
            cate+=y.tip;

            for(vector<elem>::iterator it=graf[y.nod].begin();it!=graf[y.nod].end();it++)
                if((it->val+dist[y.nod])<=dist[it->nod])
                {
                    dist[it->nod]=it->val+dist[y.nod];
                    //cout<<"se baga "<<(it->nod)<<' '<<dist[it->nod]<<' '<<it->tip<<endl;
                    coada.push(elem(it->nod,dist[it->nod],it->tip));
                }
        }
    }
}

int main()
{
    cin>>n>>m>>k;

    int a,b,x;
    while(m--)
    {
        cin>>a>>b>>x;

        graf[a].push_back(elem(b,x,0));
        graf[b].push_back(elem(a,x,0));
        //cout<<"muchii cu prioritate 0 (importante, netren) "<<a<<' '<<b<<endl;
    }

    int cop=k;
    while(k--)
    {
        cin>>b>>x;
        a=1;

        graf[a].push_back(elem(b,x,1));
        graf[b].push_back(elem(a,x,1));

        //cout<<"muchii cu prioritate 1 (portante, tren) "<<a<<' '<<b<<endl;
    }
    k=cop;

    dijkstra();
    cout<<k-cate<<'\n';

    return 0;
}