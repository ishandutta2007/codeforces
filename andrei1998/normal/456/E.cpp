#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>

#define NMAX 300005

using namespace std;

vector<int> graf[NMAX];
int deg[NMAX];
bitset<NMAX> viz;

int tata[NMAX];
int h[NMAX];
int diametru[NMAX];
int lant[NMAX];

int f(int x)
{
    if(x!=tata[x])
        tata[x]=f(tata[x]);
    return tata[x];
}

inline void unite(int a,int b)
{
    a=f(a);
    b=f(b);

    if(a==b)
        return;

    if(h[a]>h[b]){
        tata[b]=a;
    }
    else{
        if(h[a]==h[b])
            h[b]++;
        tata[a]=b;
    }
}

inline void unite2(int a,int b)
{
    a=f(a);
    b=f(b);

    if(a==b)
        return;

    if(h[a]>h[b]){
        tata[b]=a;
        diametru[a]=max(max(diametru[a],diametru[b]),lant[a]+lant[b]+1);
        lant[a]=min(max(lant[a],lant[b]+1),max(lant[b],lant[a]+1));
    }
    else{
        if(h[a]==h[b])
            h[b]++;
        tata[a]=b;
        diametru[b]=max(max(diametru[a],diametru[b]),lant[a]+lant[b]+1);
        lant[b]=min(max(lant[a],lant[b]+1),max(lant[b],lant[a]+1));
    }
}

int dist[NMAX];
int nod[NMAX];

int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,q,a,b;
    cin>>n>>m>>q;

    for(int i=1;i<=n;i++){
        tata[i]=i;
        h[i]=1;
    }

    while(m--){
        cin>>a>>b;
        deg[a]++;
        deg[b]++;

        graf[a].push_back(b);
        graf[b].push_back(a);
        unite(a,b);
    }

    //Calculam centroizii
    queue<int> coada;
    for(int i=1;i<=n;i++)
        if(deg[i]<=1)
            coada.push(i);

    vector<int> centroids;
    while(!coada.empty()){
        int y=coada.front();
        coada.pop();
        viz[y]=1;

        for(vector<int>::iterator it=graf[y].begin();it!=graf[y].end();it++)
            if(!viz[*it]){
                deg[*it]--;
                if(deg[*it]==1)
                    coada.push(*it);
            }

        if(!deg[y])
            centroids.push_back(y);
    }

    //Calculam distantele de la centroizi la frunze
    viz&=0;
    for(int i=0;i<centroids.size();i++){
        coada.push(centroids[i]);
        viz[centroids[i]]=1;
    }

    while(!coada.empty()){
        int y=coada.front();
        coada.pop();

        for(vector<int>::iterator it=graf[y].begin();it!=graf[y].end();it++)
            if(!viz[*it]){
                viz[*it]=1;
                dist[*it]=dist[y]+1;

                coada.push(*it);
            }
    }

    for(int i=1;i<=n;i++){
        int rad=f(i);
        if(dist[i]>=lant[rad]){
            lant[rad]=dist[i];
            nod[rad]=i;
        }
    }

    //Calculam diametrele
    viz&=0;
    memset(dist,0,sizeof(dist));

    for(int i=1;i<=n;i++)
        if(!viz[nod[f(i)]]){
            coada.push(nod[f(i)]);
            viz[nod[f(i)]]=1;
        }

    while(!coada.empty()){
        int y=coada.front();
        coada.pop();

        for(vector<int>::iterator it=graf[y].begin();it!=graf[y].end();it++)
            if(!viz[*it]){
                viz[*it]=1;
                dist[*it]=dist[y]+1;

                coada.push(*it);
            }
    }

    for(int i=1;i<=n;i++){
        int rad=f(i);
        if(dist[i]>=diametru[rad])
            diametru[rad]=dist[i];
    }

    //Raspundem la queri-uri
    while(q--){
        int tip;
        cin>>tip;

        if(tip==1){
            int x;
            cin>>x;

            cout<<diametru[f(x)]<<'\n';
        }
        else{
            int a,b;
            cin>>a>>b;

            unite2(a,b);
        }
    }

    return 0;
}