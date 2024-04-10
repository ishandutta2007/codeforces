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

const int maxn = 1e5;
const int inf = 1e9;
const int T = 48;
const long long p = 95542721;

int tree[maxn * 4][T];
int upd[maxn * 4];
int a[maxn];
int cur[maxn * 4];

void build(int v, int l, int r){
    if (l + 1 == r){
        tree[v][0] = a[l];
        for (int i = 1; i < T; i++)
            tree[v][i] = ((tree[v][i - 1] * 1ll * tree[v][i - 1]) % p * tree[v][i - 1]) % p;    
        return;     
    }
    build(v * 2 + 1, l, (l + r) / 2);
    build(v * 2 + 2, (l + r) / 2, r);
    for (int i = 0; i < T; i++)
        tree[v][i] = (tree[v * 2 + 1][i] + tree[v * 2 + 2][i]) % p;
}

void push(int v){
    cur[v * 2 + 1] = (cur[v * 2 + 1] + upd[v]) % T;
    cur[v * 2 + 2] = (cur[v * 2 + 2] + upd[v]) % T;
    upd[v * 2 + 1] = (upd[v * 2 + 1] + upd[v]) % T;
    upd[v * 2 + 2] = (upd[v * 2 + 2] + upd[v]) % T;
    upd[v] = 0; 
}

void add(int v, int l, int r, int ll, int rr){
    if (rr <= l || r <= ll)
        return;
    if (l <= ll && rr <= r){
        cur[v] = (cur[v] + 1) % T;
        upd[v] = (upd[v] + 1) % T;
        return;
    }
    push(v);
    add(v * 2 + 1, l, r, ll, (ll + rr) / 2);
    add(v * 2 + 2, l, r, (ll + rr) / 2, rr);
    cur[v] = 0;
    for (int i = 0; i < T; i++)
        tree[v][i] = (tree[v * 2 + 1][(cur[v * 2 + 1] + i) % T] + tree[v * 2 + 2][(cur[v * 2 + 2] + i) % T]) % p;
}

int getsum(int v, int l, int r, int ll, int rr){
    if (rr <= l || r <= ll)
        return 0;
    if (l <= ll && rr <= r){
        return tree[v][cur[v]];
    }
    push(v);
    return (getsum(v * 2 + 1, l, r, ll, (ll + rr) / 2) +
           getsum(v * 2 + 2, l, r, (ll + rr) / 2, rr)) % p;
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, t, l, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    build(0, 0, n);
//  for (int i = 0; i < n * 2; i++){
//      for (int j = 0; j < 10; j++)
//          epr("%d ", tree[i][j]);
//      epr("\n");
//  }

    
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &t, &l, &r); l--;
        if (t == 1)
            printf("%d\n", getsum(0, l, r, 0, n));
        if (t == 2)
            add(0, l, r, 0, n);             
    }
//  for (int i = 0; i < n * 2; i++)
//      epr("%d%c", i, " \n"[i == n * 2 - 1]);
//  for (int i = 0; i < n * 2; i++)
//      epr("%d%c", cur[i], " \n"[i == n * 2 - 1]);
// 
//  
    return 0;
}