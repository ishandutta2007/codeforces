#include <bitset>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graf[100005];

int n;
int dist[100005];
queue<int> coada;
bitset<100005> viz;

int bfs(int nod){
    viz&=0;

    viz[nod]=1;
    dist[nod]=1;
    coada.push(nod);

    int y;
    vector<int>::iterator it;
    while(!coada.empty()){
        y=coada.front();
        coada.pop();

        for(it=graf[y].begin();it!=graf[y].end();it++)
            if(!viz[*it]){
                viz[*it]=1;
                dist[*it]=dist[y]+1;
                coada.push(*it);
            }
    }

    int maxim=0;
    int x=0;

    for(int i=1;i<=n;i++) {
        if(dist[i]>maxim){
            maxim=dist[i];
            x=i;
        }
    }

    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int m;
    cin>>n >> m;

    int a,b;
    while(m--){
        cin>>a>>b;

        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    a=bfs(1);
    b=bfs(a);

    cout<<dist[b] - 1<<'\n';
    return 0;
}