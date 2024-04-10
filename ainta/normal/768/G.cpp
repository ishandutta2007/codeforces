#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#define SZ 131072
using namespace std;
vector<int>E[101000], IT[SZ+SZ];
int n, C[101000], ReNum[SZ+1], Num[101000], Ed[101000], cnt, Res[101000];
int cc;
void DFS(int a){
    int i;
    C[a] = 1;
    for(i=0;i<E[a].size();i++){
        DFS(E[a][i]);
        C[a] += C[E[a][i]];
    }
}
int RT[101000], par[101000];
void DFS3(int a, int pp, int rt){
    int i, Mx = -1, x = -1;
    RT[a] = rt;
    par[a] = pp;
    Num[a] = ++cnt;
    ReNum[cnt] = a;
    for(i=0;i<E[a].size();i++){
        if(Mx<C[E[a][i]])Mx=C[E[a][i]], x=i;
    }
    if(x!=-1) DFS3(E[a][x], a, rt);
    for(i=0;i<E[a].size();i++){
        if(i!=x){
            DFS3(E[a][i], a, E[a][i]);
        }
    }
    Ed[a] = cnt;
}
void Build(int nd, int b, int e){
    int i;
    IT[nd].resize(e-b+1);
    for(i=b;i<=e;i++)IT[nd][i-b] = C[ReNum[i]];
    sort(IT[nd].begin(),IT[nd].end());
    if(b==e)return;
    int m = (b+e)>>1;
    Build(nd*2,b,m);
    Build(nd*2+1,m+1,e);
}
int Max(int b, int e, int c){
    b+=SZ, e+=SZ;
    int Mx = c, sz = 1;
    while(b<=e){
        if(b&1){
            int t = lower_bound(IT[b].begin(),IT[b].end(),c/2)-IT[b].begin();
            if(t!=sz){
                Mx = min(Mx,abs(IT[b][t]*2-c));
            }
            if(t){
                t--;
                Mx = min(Mx,abs(IT[b][t]*2-c));
            }
        }
        if(!(e&1)){
            int t = lower_bound(IT[e].begin(),IT[e].end(),c/2)-IT[e].begin();
            if(t!=sz){
                Mx = min(Mx,abs(IT[e][t]*2-c));
            }
            if(t){
                t--;
                Mx = min(Mx,abs(IT[e][t]*2-c));
            }
        }
        b=(b+1)>>1,e=(e-1)>>1, sz<<=1;
    }
    return Mx;
}
void DFS2(int a){
    int i;
    for(i=0;i<E[a].size();i++){
        DFS2(E[a][i]);
    }
    vector<int>TP;
    int Mx = -1, pv = -1;
    for(i=0;i<E[a].size();i++){
        TP.push_back(C[E[a][i]]);
        if(Mx < C[E[a][i]])Mx=C[E[a][i]], pv = E[a][i];
    }
    if(C[a] != n){
        TP.push_back(n-C[a]);
        if(Mx < n-C[a])Mx = n-C[a], pv = 0;
    }
    sort(TP.begin(),TP.end());
    Res[a] = Mx;
    if(TP.size()==1)return;
    if(pv){
        if(a==1){
            //  printf("111 %d %d %d %d %d\n",TP[0],Mx, TP[TP.size()-2], Num[pv], Ed[pv]);
        }
        int g = Max(Num[pv], Ed[pv], (Mx - TP[0]));
        g = (Mx-TP[0]-g)/2;
        Res[a] = max(max(TP[0] + g, Mx - g), TP[TP.size()-2]);
    }
    else{
        int rr = Mx;
        if(Num[pv] != 1){
            vector<int>TT;
            int t = par[a];
            int g = Mx-TP[0], g2 = Mx-TP[0];
            int ee = Num[a]-1;
            while(t){
                g2 = min(g2, Max(Num[t]+1, ee, (Mx-TP[0])));
                g = min(g, Max(Num[RT[t]], Num[t], (Mx - TP[0]) + C[a]*2));
                ee = Num[RT[t]]-1;
                t = par[RT[t]];
            }
            g2 = (Mx-TP[0]-g2)/2;
            g = (Mx-TP[0]+C[a]*2-g)/2;
            g -= C[a];
            rr = max(TP[TP.size()-2], max(TP[0] + g, Mx - g));
            rr = min(rr,max(TP[TP.size()-2], max(TP[0] + g2, Mx - g2)));
        }
        if(Ed[a] != n){
            int g = Max(Ed[a]+1, n, (Mx - TP[0]));
            g = (Mx-TP[0]-g)/2;
            rr = min(rr, max(max(TP[0] + g, Mx - g), TP[TP.size()-2]));
        }
        Res[a] = rr;
    }
}
struct AA{
    int a, c;
    bool operator<(const AA &p)const{
        return c<p.c;
    }
}ord[101000];
int main(){
    int i, a, b, rt = 0;
    scanf("%d",&n);
    if(n==1){
        printf("0\n");
        return 0;
    }
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        if(!a)rt = b;
        else E[a].push_back(b);
    }
    DFS(rt);
    DFS3(rt, 0, rt);
    Build(1,0,SZ-1);
    DFS2(rt);
    for(i=1;i<=n;i++)printf("%d\n",Res[i]);
}