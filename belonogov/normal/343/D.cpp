#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 5e5 + 2;
const int inf = 1e9;

struct node{
    int val, upd;   
    node(){
        val = 0;
        upd = -1;
    }
};

int tin[maxn];
int tout[maxn];
node treeD[maxn * 4 * 2];
node treeU[maxn * 4 * 2];
vector < int > e[maxn];

int tmr = 0;

void dfs(int v, int p){
    tin[v] = tmr++;
    for (int i = 0; i < (int)e[v].size(); i++)
        if (e[v][i] != p)
            dfs(e[v][i], v);
    
    tout[v] = tmr++;
}

void push(node * tree, int v){
    if (tree[v].upd == -1)
        return;
    tree[v * 2 + 1].val = tree[v].upd;
    tree[v * 2 + 2].val = tree[v].upd;
    tree[v * 2 + 1].upd = tree[v].upd;
    tree[v * 2 + 2].upd = tree[v].upd;
    tree[v].upd = -1;   
}

void add(node * tree, int v, int l, int r, int ll, int rr, int val){
    if (r <= ll || rr <= l)
        return;
    if (l <= ll && rr <= r){
        tree[v].val = val;
        tree[v].upd = val;      
        return;     
    }
    push(tree, v);
    add(tree, v * 2 + 1, l, r, ll, (ll + rr) / 2, val);
    add(tree, v * 2 + 2, l, r, (ll + rr) / 2, rr, val);
    tree[v].val = max(tree[v * 2 + 1].val, tree[v * 2 + 2].val);    
}

int getmax(node * tree, int v, int l, int r, int ll, int rr){
    if (r <= ll || rr <= l)
        return -inf;
    if (l <= ll && rr <= r)
        return tree[v].val;
    push(tree, v);
    return max(getmax(tree, v * 2 + 1, l, r, ll, (ll + rr) / 2),
               getmax(tree, v * 2 + 2, l, r, (ll + rr) / 2, rr));   
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, v, u, m, t;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++){
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);     
    }
    dfs(0, -1);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &t, &v); v--;
        if (t == 1)
            add(treeD, 0, tin[v], tout[v], 0, tmr, i);
        if (t == 2)
            add(treeU, 0, tin[v], tin[v] + 1, 0, tmr, i);
        if (t == 3){
            int t1 = getmax(treeD, 0, tin[v], tin[v] + 1, 0, tmr);
            int t2 = getmax(treeU, 0, tin[v], tout[v], 0, tmr);
            printf((t1 > t2) ? "1\n" : "0\n");
        }
        
    }
    
 
    return 0;
}