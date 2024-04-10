#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define N_ 1000000
int INF = 2e9, n, m, Q;

struct node {
    node *l, *r, *p, *pp;
    int num, cnt;
    bool inv;
    int val, Mn;
    node(int a) : l(0), r(0), p(0), pp(0), num(a) , cnt(0) , inv(0), val(INF), Mn(INF) {}
};

node *Tree[N_];

void propagate(node *cur) {
    if (!cur->inv) return;
    node *tmp = cur->l;
    cur->l = cur->r;
    cur->r = tmp;
    cur->inv = false;
    if (cur->l) cur->l->inv = !cur->l->inv;
    if (cur->r) cur->r->inv = !cur->r->inv;
}

void reset(node *cur) {
    cur->Mn = cur->val;
    if (cur->l && cur->Mn > cur->l->Mn) cur->Mn = cur->l->Mn;
    if (cur->r && cur->Mn > cur->r->Mn) cur->Mn = cur->r->Mn;
    cur->cnt = 1;
    if (cur->l) cur->cnt += cur->l->cnt;
    if (cur->r) cur->cnt += cur->r->cnt;
}
 
void rotate(node *cur) {
    node *p = cur->p;
    propagate(p);
    propagate(cur);
    if (cur == p->l) {
        if ((p->l = cur->r)) cur->r->p = p;
        cur->r = p;
    } else {
        if ((p->r = cur->l)) cur->l->p = p;
        cur->l = p;
    }
    cur->p = p->p;
    p->p = cur;
    if (cur->p) {
        if (cur->p->l == p) cur->p->l = cur;
        else cur->p->r = cur;
    } else {
        cur->pp = p->pp;
        p->pp = NULL;
    }
    reset(p);
    reset(cur);
}

bool isRoot(node * x) {
    return (x->p == 0 || (x->p->l != x && x->p->r != x));
}

void splay(node * x) {
    while (!isRoot(x)) {
        node * p = x->p;
        if (!isRoot(p)) propagate(p->p);
        propagate(p);
        propagate(x);
        if (!isRoot(p)) {
            if ((x == p->l) == (p == p->p->l)) rotate(p);
            else rotate(x);
        }
        rotate(x);
    }
    propagate(x);
}
 

void access(node *cur) {
    splay(cur);
    propagate(cur);
    if (cur->r) {
        cur->r->pp = cur;
        cur->r->p = NULL;
        cur->r = NULL;
    }
    while (cur->pp) {
        node *pp = cur->pp;
        splay(pp);
        propagate(pp);
        if (pp->r) {
            pp->r->pp = pp;
            pp->r->p = NULL;
        }
        pp->r = cur;
        cur->p = pp;
        cur->pp = NULL;
        splay(cur);
    }
}
 
node *find_root(node *cur) {
    access(cur);
    while (cur->l) {
        cur = cur->l;
        propagate(cur);
    }
    access(cur);
    return cur;
}

 
void link(node *root, node *cur) {
    access(root);
    access(cur);
    root->l = cur;
    cur->p = root;
    reset(root);
    reset(cur);
}
 
void cut(node *cur) {
    access(cur);
    if (cur->l) {
        cur->val = INF;
        cur->l->p = NULL;
        cur->l = NULL;
        reset(cur);
    }
}



node *lca(node *cur, node *nxt) {
    access(cur);
    access(nxt);
    splay(cur);
    return cur->pp ? cur->pp : cur;
}

int path_min(node *cur, node *nxt) {
    if(cur==nxt)return INF;
    access(cur);
    access(nxt);
    splay(cur);
    cur->r->p = NULL;
    splay(nxt);
    nxt->p = cur;

//    return min(cur->val, nxt->Mn);
    int res = cur->val > nxt->val ? nxt->val : cur->val;
    return nxt->l && res > nxt->l->Mn ? nxt->l->Mn : res;

}


int query(node * x, node * y) {
    node * p = lca(y, x);
    return min(path_min(p, x), path_min(p, y));
}

void make_root(node *cur) {
    access(cur);
    cur->inv = !cur->inv;
}

node *findRoot(node *cur) {
    access(cur);
    while (cur->l) {
        cur = cur->l;
        propagate(cur);
    }
    access(cur);
    return cur;
}

int depth(node * x) { access(x); if (x->l) return x->l->cnt; return 0; }

void connect(int a, int b) {
    make_root(Tree[a]);
    link(Tree[a], Tree[b]);
}

struct Edge{
    int a, b;
}Ed[N_];


void Add(int a, int b, int c){
    //printf("add %d %d %d\n",a,b,c);
    Tree[n+c] = new node(n+c);
    Tree[n+c]->val = c;
    connect(a, n+c);
    connect(b, n+c);
}

void Delete(int a, int b, int c){
    //printf("del %d %d %d\n",a,b,c);
    make_root(Tree[a]);
    cut(Tree[n+c]);
    make_root(Tree[b]);
    cut(Tree[n+c]);
}

bool Merge(int a, int b, int c){
    //printf("merge %d %d %d\n",a,b,c);
    make_root(Tree[a]);
    if(findRoot(Tree[a])==findRoot(Tree[b])){
        int d = depth(Tree[b]);
        //printf("%d\n",d);
        if(d%4==0){
            return false;
        }
        int tp = query(Tree[a],Tree[b]);
        if(tp < c){
            Edge t;
            if(tp>m)t=Ed[tp-m];
            else t=Ed[tp];
            Delete(t.a, t.b, tp);
            Add(a,b,c);
        }
        return true;
    }
    Add(a,b,c);
    return true;
}

int PV[N_];

int main(){
    int i;
    scanf("%d%d%d",&n,&m,&Q);
    for(i=1;i<=n;i++){
        Tree[i] = new node(i);
    }
    for(i=1;i<=m;i++){
        int a, b;
        scanf("%d%d",&Ed[i].a,&Ed[i].b);
    }

    for(i=m;i>=1;i--){
        if(!Merge(Ed[i].a,Ed[i].b, i))break;
    }
    PV[0] = i+1;
    if(PV[0]==1){
        for(i=1;i<=m;i++){
            PV[i]=i+1;
        }
    }
    else{
        for(i=1;i<=m;i++){
            int pv = PV[i-1];
            while(!Merge(Ed[i].a,Ed[i].b, m+i)){
                if(pv==m+1){
                    for(;i<=m;i++){
                        PV[i]=-1;
                    }
                    break;
                }
                //printf("%d\n",pv);
                //printf("%d %d %d\n",Ed[pv].a,Ed[pv].b, query(Tree[Ed[pv].a],Tree[Ed[pv].b]));
                //printf("%d %d\n",findRoot(Tree[Ed[pv].a])->num, findRoot(Tree[Ed[pv].b])->num);
                if(query(Tree[Ed[pv].a],Tree[Ed[pv].b]) == pv){
                    Delete(Ed[pv].a, Ed[pv].b, pv);
                }
                pv++;
            }
            if(PV[m]==-1)break;
            PV[i]=pv;
        }
    }
    /*for(i=0;i<=m;i++){
        printf("%d %d\n",i,PV[i]);
    }*/
    while(Q--){
        int a, b;
        scanf("%d%d",&a,&b);
        if(PV[a-1]==-1){
            puts("YES");
            continue;
        }
        if(PV[a-1]>b+1){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }

}