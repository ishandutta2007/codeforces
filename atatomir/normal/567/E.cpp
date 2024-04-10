#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define foreach(V) for(auto it=V.begin();it!=V.end();it++)
#define fordef(it,a,b) for(it=a;it<=b;it++)
#define mp make_pair
#define pb push_back
#define ll long long
#define pa(a,b) pair< a,b >

#define maxN 100011
#define inf (1LL<<60)
#define mod1 666013
#define mod2 1000007
#define mod3 32176598

struct ModLongLong{
    long long m1,m2,m3;
    void init(long long v){
        m1 = m2 = m3 = v;
    }
    void operator+(ModLongLong& who){
        m1 = m1+who.m1;
        m2 = m2+who.m2;
        m3 = m3+who.m3;
        if(m1 >= mod1) m1-=mod1;
        if(m2 >= mod2) m2-=mod2;
        if(m3 >= mod3) m3-=mod3;
    }
    void operator*(ModLongLong& who){
        m1 = m1*who.m1;
        m2 = m2*who.m2;
        m3 = m3*who.m3;
        m1%=mod1;
        m2%=mod2;
        m3%=mod3;
    }
    bool operator==(ModLongLong& who){
        return (m1==who.m1) && (m2==who.m2) && (m3==who.m3);
    }
};

int n,m,S,D,i,x,y;
vector< pair<int,long long> > list[2][maxN];
long long  c;
long long  dist[2][maxN];
ModLongLong  ways[2][maxN];
priority_queue< pair<long long,int> > H;
vector< pair< pair<int,int>,long long > > Edges;

void Dijkstra(int S,int D,int way){
    while(!H.empty()) H.pop();
    for(int i=1;i<=n;i++) {dist[way][i] = inf; ways[way][i].init(0);}

    ways[way][S].init(1); dist[way][S] = 0;
    H.push( mp(0,S) );
    while(!H.empty()){
        auto act = H.top(); H.pop();
        //if(act.second == D) continue;
        if(-act.first != dist[way][ act.second ]) continue;

        for(auto wh:list[way][act.second]){
            long long newCost = dist[way][act.second] + wh.second;

            if(newCost == dist[way][wh.first]){
                ways[way][wh.first] + ways[way][ act.second ];
            } else
            if(newCost <  dist[way][wh.first]){
                ways[way][wh.first] = ways[way][ act.second ];
                dist[way][wh.first] = newCost;
                H.push( mp( -dist[way][wh.first] , wh.first) );
            }
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d%d",&n,&m,&S,&D);
    for(i=1;i<=m;i++){
        scanf("%d%d%I64d",&x,&y,&c);
        list[0][x].pb( mp( y,c ) );
        list[1][y].pb( mp( x,c ) );
        Edges.pb( mp( mp(x,y) , c ) );
    }

    Dijkstra(S,D,0);
    Dijkstra(D,S,1);

    for(auto act:Edges){
        x = act.first.first;
        y = act.first.second;
        c = act.second;

        ModLongLong aux = ways[0][x]; aux * ways[1][y];
        if(dist[0][x]+c+dist[1][y] == dist[0][D] && aux   == ways[0][D]   ) {
            printf("YES\n");
        } else {
            long long dif = -dist[0][D] + dist[0][x] + dist[1][y] + c+1;
            if(dif >= c) printf("NO\n");
            else         printf("CAN %I64d\n",dif);
        }
    }


    return 0;
}