#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 600005
#define maxk 600005

using namespace std;
typedef long long ll;

int n, k, par[maxk], siz[maxk], val[maxk], m;
bool consi[maxn];// into m.
void updConsi(int i, bool x){
  if(consi[i] == x) return;
  if(x) m += siz[i];
  else m -= siz[i];
  consi[i] = x;
}
// node 0, 2, 4, ..., 2(k - 1): true
// node 1, 3, 5, ..., 2k - 1: false
// val: 0-false, 1-true, -1-TBD.
void ini(int x){
  m = 0;
  for(int i = 0;i < x;i++){
    par[i] = i;
    val[i] = -1;
    siz[i] = 1 - (i & 1);
    consi[i] = (i & 1);
  }
}
int fin(int u){
  if(par[u] == u) return u;
  return par[u] = fin(par[u]);
}
void uni(int u, int v){
  u = fin(u), v = fin(v);
  if(u == v) return;
  par[u] = v;
  siz[v] += siz[u];
  if(val[u] != -1) val[v] = val[u];
}

char s[maxn];
vector <int> sets[maxn];
int main(){
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for(int i = 0;i < k;i++){
    int c, x;
    scanf("%d", &c);
    for(int j = 0;j < c;j++){
      scanf("%d", &x);
      sets[x].push_back(i);
    }
  }
  ini(k << 1);
  for(int i = 1;i <= n;i++){
    if((int)sets[i].size() == 1){
      int u = sets[i].front(), u1 = fin(u << 1), u2 = fin(u << 1 | 1);
      if(s[i] == '0'){
        val[u1] = 1;
        updConsi(u1, true);
        val[u2] = 0;
        updConsi(u2, false);
      }else{
        val[u1] = 0;
        updConsi(u1, false);
        val[u2] = 1;
        updConsi(u2, true);
      }
    }else if((int)sets[i].size() == 2){
      int u = sets[i].front(), u1 = fin(u << 1), u2 = fin(u << 1 | 1);
      int v = sets[i].back(), v1 = fin(v << 1), v2 = fin(v << 1 | 1);
      updConsi(u1, false);
      updConsi(u2, false);
      updConsi(v1, false);
      updConsi(v2, false);
      if(s[i] == '0'){
        uni(u1, v2);
        uni(u2, v1);
      }else{
        uni(u1, v1);
        uni(u2, v2);
      }
      if(val[v1] == -1){
        if(siz[v1] <= siz[v2]) updConsi(v1, true);
        else updConsi(v2, true);
      }else if(val[v1] == 1){
        updConsi(v1, true);
      }else{
        updConsi(v2, true);
      }
    }
    printf("%d\n", m);
  }
  return 0;
}