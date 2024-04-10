#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define pii pair<int,int>
#define SZ 131072
using namespace std;
int H, W, n, cnt, D[501000], Mod = 1000000007, Q[501000], head, tail, Deg[501000];
vector<int>E[501000];
set<pii>IT[SZ+SZ];
struct point{
    int x, y, num;
    bool operator <(const point &p)const{
        return y<p.y;
    }
}w[301000];
struct Seg{
    int l, r, y, h, ck, num;
    bool operator <(const Seg &p)const{
        return y < p.y;
    }
}P[201000];
void Ins(Seg &a){
    int b = a.l + SZ, e = a.r + SZ, h = a.h, num = a.num;
    while(b<=e){
        if(b&1) IT[b].insert(pii(h,num));
        if(!(e&1)) IT[e].insert(pii(h,num));
        b=(b+1)>>1,e=(e-1)>>1;
    }
}
void Del(Seg &a){
    int b = a.l + SZ, e = a.r + SZ, h = a.h, num = a.num;
    while(b<=e){
        if(b&1) IT[b].erase(pii(h,num));
        if(!(e&1)) IT[e].erase(pii(h,num));
        b=(b+1)>>1,e=(e-1)>>1;
    }
}
int Get(int a){
    int r = 0, M = -1;
    a += SZ;
    while(a){
        if(!IT[a].empty()){
            auto it = IT[a].end();
            it--;
            if(it->first > M){
                M = it->first;
                r = it->second;
            }
        }
        a>>=1;
    }
    return r;
}
int main(){
    int i;
    scanf("%d%d%d",&H,&W,&n);
    for(i=1;i<=n;i++){
        int y, l, r, s;
        scanf("%d%d%d%d",&y,&l,&r,&s);
        P[i] = {l,r,y+1,y,0,W+i};
        P[n+i] = {l,r,y+s+1,y,1,W+i};
        if(l==1){
            w[cnt++] = {r+1,y,W+i};
            w[cnt++] = {r+1,y,W+i};
        }
        else if(r==W){
            w[cnt++] = {l-1,y,W+i};
            w[cnt++] = {l-1,y,W+i};
        }
        else{
            w[cnt++] = {l-1,y,W+i};
            w[cnt++] = {r+1,y,W+i};
        }
    }
    for(i=1;i<=W;i++)w[cnt++] = {i,H+1,i};
    sort(w,w+cnt);
    sort(P+1,P+n+n+1);
    int pv = 1;
    for(i=0;i<cnt;i++){
        while(pv<=n+n && P[pv].y <= w[i].y){
            if(!P[pv].ck)Ins(P[pv]);
            else Del(P[pv]);
            pv++;
        }
        int t = Get(w[i].x);
        E[w[i].num].push_back(t);
        Deg[t]++;
    }
    for(i=1;i<=W;i++)D[i]=1;
    for(i=0;i<=n+W;i++){
        if(!Deg[i]){
            Q[++tail] = i;
        }
    }
    while(head < tail){
        int x = Q[++head];
        for(i=0;i<E[x].size();i++){
            int y = E[x][i];
            D[y] = (D[y] + D[x])%Mod;
            Deg[y]--;
            if(!Deg[y])Q[++tail] = y;
        }
    }
    printf("%d\n",D[0]);
}