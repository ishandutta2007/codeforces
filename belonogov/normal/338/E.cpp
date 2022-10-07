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

const int maxn = 2e5;
const int inf = 1e9;

int a[maxn];
int b[maxn];
int p[maxn];
int tree[maxn * 4];
int upd[maxn * 4];
int n, m, h;

void build(int v, int ll, int rr){
    if (rr - ll == 1){
        tree[v] = - ll - 1; 
        return;     
    }
    build(v * 2 + 1, ll, (ll + rr) / 2);
    build(v * 2 + 2, (ll + rr) / 2, rr);
    tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void push(int v){
    tree[v * 2 + 1] += upd[v];
    tree[v * 2 + 2] += upd[v];
    upd[v * 2 + 1] += upd[v];
    upd[v * 2 + 2] += upd[v];
    upd[v] = 0; 
}

void add(int v, int l, int r, int ll, int rr, int val){
    if (rr <= l || r <= ll)
        return;
    if (l <= ll && rr <= r){
        tree[v] += val;
        upd[v] += val;
        return;
    }
    push(v);
    add(v * 2 + 1, l, r, ll, (ll + rr) / 2, val);
    add(v * 2 + 2, l, r, (ll + rr) / 2, rr, val);
    tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);    
}

void print(int v, int ll, int rr, int t = 0){
    if (rr - ll > 1)
        print(v * 2 + 2, (ll + rr) / 2, rr, t + 1);
    for (int i = 0; i < t; i++)
        printf("\t");
    printf("tree upd %d %d\n", tree[v], upd[v]);
    if (rr - ll > 1)
        print(v * 2 + 1, ll, (ll + rr) / 2, t + 1); 
    if (t == 0)
        printf("\n\n");
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int ans = 0;
    scanf("%d%d%d", &n, &m, &h);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(b, b + m);
    for (int i = 0; i < n; i++)
        p[i] = lower_bound(b, b + m, h - a[i]) - b;
    
    build(0, 0, m);
    for (int i = 0; i < m; i++)
        add(0, p[i], m, 0, m, 1);
    
//  print(0, 0, m);
    
    ans += tree[0] >= 0;
    for (int i = m; i < n; i++){
        add(0, p[i], m, 0, m, 1);
//      print(0, 0, m);
        add(0, p[i - m], m, 0, m, -1);
//      print(0, 0, m);
        ans += tree[0] >= 0;        
    }
    printf("%d\n", ans);
    
    
 
    return 0;
}