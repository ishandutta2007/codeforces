#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, W, H;
struct point{
    int x, y, num;
    bool operator <(const point &p)const{
        return x!=p.x?x<p.x:y>p.y;
    }
}w[101000], Res[101000];
vector<point>G[301000], E[301000];
int main(){
    int i, ck, a, t, x, y, x2, y2, j;
    scanf("%d%d%d",&n,&W,&H);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&ck,&a,&t);
        if(ck == 1)x = x2 = a, y = -t, y2 = H;
        else x = -t, x2 = W, y = y2 = a;
        E[x+y+100000].push_back({x,y,i});
        G[x+y+100000].push_back({x2,y2,i});
    }
    for(i=0;i<=210000;i++){
        if(E[i].empty())continue;
        sort(E[i].begin(),E[i].end());
        sort(G[i].begin(),G[i].end());
        for(j=0;j<E[i].size();j++) Res[E[i][j].num] = G[i][j];
    }
    for(i=0;i<n;i++)printf("%d %d\n",Res[i].x,Res[i].y);
}