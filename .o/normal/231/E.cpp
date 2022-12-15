#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define V_ 100005
#define E_ 200005
#define INF 1000000007

class Edge;
class Graph{
public:
    int vertex, edge;
    int *nxt, *lnk, *gst;
    void resize(int, int); void add(int, int);
    Edge begin(int);
};

class Edge{
public:
    Graph *gph; int ed, nd;
    int operator* (){ return gph->nxt[ed]; }
    Edge operator++ (){ ed = gph->lnk[ed]; return *this; }
};

class UF{
    int n; 
public:
    int *Gr, *Rnk;
    void resize(int); bool merge(int, int);
    int find_group(int);
};

int V, E, Q;
Graph G, Tree;
int Cyc[V_+1], GRN, GRN_C;
Edge Stk[V_+1]; int tp;
bool Chk[V_+1];

UF Group;
int Que[V_+1], Qf, Qr;
int Par[V_+1][17];
int Cnt[V_+1], Level[V_+1];

int pow2[V_+1];

int main(){
    int i, j;

    scanf("%d%d",&V,&E); G.resize(V, E*2);
    pow2[0] = 1;
    for(i=1; i<=V; i++) pow2[i] = (pow2[i-1] * 2) % INF;
    while(E--){
        int u, v; scanf("%d%d",&u,&v); 
        G.add(u, v); G.add(v, u);
    }

    Stk[++tp] = G.begin(1); Chk[1] = true;
    while(tp > 0){
        Edge &t = Stk[tp]; bool suc = false;
        for( ; t.ed ; ++t){
            if(*t == Stk[tp-1].nd) continue;
            if(Cyc[*t]) continue;
            if(!Chk[*t]){
                Stk[++tp] = G.begin(*t);
                Chk[*t] = true; ++t; suc = true;
                break;
            }
            for(++GRN, i = tp; i > 0; i--){
                Cyc[Stk[i].nd] = GRN;
                if(Stk[i].nd == *t) break;
            }
        }
        if(!suc && t.ed <= 0) --tp;
    }

    GRN_C = GRN;
    for(i=1; i<=V; i++){
        if(!Cyc[i]) Cyc[i] = ++GRN;
    }
    
    Group.resize(GRN); Tree.resize(GRN, GRN*2-2);
    for(i=1; i<=V; i++) for(Edge e = G.begin(i); e.ed; ++e){
        if(Group.merge(Cyc[i], Cyc[*e])){
            Tree.add(Cyc[i], Cyc[*e]); Tree.add(Cyc[*e], Cyc[i]);
        }
    }
    
    for(i=1; i<=GRN; i++) Chk[i] = false;
    Que[++Qr] = 1; Chk[1] = true; Par[1][0] = -1; Cnt[1] = (1 <= GRN_C);
    while(Qf < Qr){
        int &t = Que[++Qf];
        for(Edge e = Tree.begin(t); e.ed; ++e){
            if(Chk[*e]) continue;
            Chk[*e] = true; Par[*e][0] = t; Que[++Qr] = *e;
            Cnt[*e] = Cnt[t] + (*e <= GRN_C);
            Level[*e] = Level[t] + 1;
        }
    }

    for(j=1; (1<<j)<GRN; j++) for(i=1; i<=GRN; i++){
        if(Par[i][j-1] < 0) Par[i][j] = -1;
        else Par[i][j] = Par[Par[i][j-1]][j-1];
    }

    scanf("%d",&Q); while(Q--){
        int x, y, nca, ret; scanf("%d%d",&x,&y); x = Cyc[x]; y = Cyc[y];
        ret = Cnt[x] + Cnt[y];
        if(Level[x] < Level[y]){ int tmp = x; x = y; y = tmp; }
        for(j=16; j>=0; j--){
            if(Par[x][j] >= 0 && Level[x] - (1<<j) >= Level[y]) x = Par[x][j];
        }

        if(x != y){
            for(j=16; j>=0; j--){
                if(Par[x][j] >= 0 && Par[x][j] != Par[y][j]) x = Par[x][j], y = Par[y][j];
            } 
            nca = Par[x][0];
        }else nca = x;

        printf("%d\n",pow2[ret - Cnt[nca] * 2 + (nca <= GRN_C)]);
    }
    return 0;
}

Edge Graph::begin(int u){
    Edge ret; ret.gph = this; ret.ed = gst[u]; ret.nd = u;
    return ret;
}

void Graph::resize(int vertex, int edge){
    this->vertex = vertex; this->edge = 0;
    if(!nxt) delete nxt;
    nxt = (int*)calloc(edge+1,sizeof(int));
    if(!lnk) delete lnk;
    lnk = (int*)calloc(edge+1,sizeof(int));
    if(!lnk) delete gst;
    gst = (int*)calloc(vertex+1,sizeof(int));
}

void Graph::add(int u, int v){
    ++edge; nxt[edge] = v; lnk[edge] = gst[u]; gst[u] = edge;
}

void UF::resize(int nodes){
    if(!Gr) delete Gr; if(!Rnk) delete Rnk;
    this->n = nodes;
    Gr  = new int[nodes+1]; Rnk = new int[nodes+1];
    for(int i=1; i<=this->n; i++) Rnk[i] = 1, Gr[i] = i;
}

int UF::find_group(int vt){
    int v = vt;
    while(v != Gr[v]) v = Gr[v];
    while(vt != v){ int p = Gr[vt]; Gr[vt] = v; vt = p; }
    return v;
}

bool UF::merge(int a, int b){
    a = find_group(a); b = find_group(b);
    if(a != b){
        if(Rnk[a] > Rnk[b]){ Gr[b] = a; Rnk[a] += Rnk[b]; }
        else { Gr[a] = b; Rnk[b] += Rnk[a]; }
        return true;
    } return false;
}