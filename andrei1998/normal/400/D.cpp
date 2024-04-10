#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int tata[100005];
int h[100005];

int f(int x)
{
    if(x!=tata[x])
        tata[x]=f(tata[x]);
    return tata[x];
}

void uneste(int a,int b)
{
    a=f(a),b=f(b);
    if(a!=b)
    {
        if(h[a]<h[b])
            tata[a]=b;
        else
        {
            if(h[a]==h[b])
                h[a]++;
            tata[b]=a;
        }
    }
}

struct muchie
{
    int a,b,c;
};

vector<pair<int,int> > graf[505];
muchie muchii[100005];

#define inf 100000005
int k,dist[505][505];
bool viz[505][505];
priority_queue<pair<int,int> > coada;

void dijkstra(int nod)
{
    int i;
    for(i=1;i<=k;i++)
        dist[nod][i]=inf;
    dist[nod][nod]=0;

    coada.push(make_pair(0,nod));
    pair<int,int> y;

    while(!coada.empty())
    {
        y=coada.top();
        coada.pop();

        //cout<<"scos "<<y.second<<endl;
        //cout<<viz[nod][y.second]<<endl;

        if(!viz[nod][y.second])
        {
            viz[nod][y.second]=1;
            //cout<<"aaaaaaaaaaaaaaaaaaaaaaaaavem in total "<<graf[y.second].size()<<endl;
            for(vector<pair<int,int> >::iterator it=graf[y.second].begin();it!=graf[y.second].end();it++)
            {
              //  cout<<"muchie la "<<it->first<<endl;
                if((dist[nod][y.second]+it->second)<dist[nod][it->first])
                {
                    dist[nod][it->first]=dist[nod][y.second]+it->second;
                    coada.push(make_pair(-dist[nod][it->first],it->first));
                }
            }
        }
    }
}

int main()
{
    int n,m,i,j,tip[505];
    int unde[100005];
    int ante[100005];

    cin>>n>>m>>k;

    for(i=1;i<=k;i++)
        cin>>tip[i];


    int aici=1;
    ante[1]=1;

    for(i=1;i<=n;i++)
    {
        tata[i]=i;
        h[i]=1;
        unde[i]=aici;
        tip[aici]--;
        ante[i+1]=ante[i];

        if(tip[aici]==0)
        {
            aici++;
            ante[i+1]=i+1;
        }
    }

    //cout<<"afis"<<endl;

    //for(i=1;i<=n;i++)
    //{
    //    cout<<unde[i]<<endl;
   // }

    for(i=0;i<m;i++)
    {
        cin>>muchii[i].a>>muchii[i].b>>muchii[i].c;
        if(!muchii[i].c)
            uneste(muchii[i].a,muchii[i].b);
    }

    for(i=1;i<=n;i++)
        if(f(i)!=f(ante[i]))
        {
            cout<<"No\n";
            return 0;
        }

    for(i=0;i<m;i++)
    {
        graf[unde[muchii[i].a]].push_back(make_pair(unde[muchii[i].b],muchii[i].c));

        //cout<<"adaug "<<unde[muchii[i].a]<<' '<<unde[muchii[i].b]<<' '<<muchii[i].c<<endl;
        graf[unde[muchii[i].b]].push_back(make_pair(unde[muchii[i].a],muchii[i].c));
    }

    cout<<"Yes\n";
    for(i=1;i<=k;i++)
        dijkstra(i);

    for(i=1;i<=k;i++)
    {
        if(dist[i][1]==inf)
            cout<<"-1";
        else
            cout<<dist[i][1];
        for(j=2;j<=k;j++)
        {
            if(dist[i][j]==inf)
                cout<<" -1";
            else
                cout<<' '<<dist[i][j];
        }
        cout<<'\n';
    }

    return 0;
}