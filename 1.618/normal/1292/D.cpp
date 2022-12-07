#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio{
  int it,len;
  char s[LEN + 5];
  fastio(){
    it = len = 0;
  }
  char get(){
    if(it < len) return s[it++];
    it = 0, len = fread(s,1,LEN,stdin);
    return len ? s[it++] : EOF;
  }
  bool notend(){
    char c;
    for(c = get();c == ' ' || c == '\n';c = get());
    if(it) it--;
    return c != EOF;
  }
  void put(char c){
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush(){
    fwrite(s,1,it,stdout);
  }
}buff,bufo;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll(){
  char c; ll res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(ll x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char(){
  char c;
  for(c = buff.get();c == ' ' || c == '\n';c = buff.get());
  return c;
}
#define maxk 5005
#define maxk_pri 675
#define maxV 10005
#define mp make_pair
typedef pair<int,int> P;

int pid[maxk],pri[maxk_pri],pri_num;
vector <int> factor[maxk];
// pid[p]: p(p-1)
void prime_sieve(int n){// sieve primes in [1,n]
  pid[1] = -1;
  for(int i = 2;i <= n;i++){
    if(~pid[i]){
      pid[i] = ++pri_num;
      pri[pri_num] = i;
      factor[i].push_back(i);
    }
    for(int j = 1;j <= pri_num && pri[j] * i <= n;j++){
      int x = pri[j] * i;
      pid[x] = -1;
      factor[x] = factor[i];
      if(i % pri[j] == 0) break;
      else factor[x].insert(factor[x].begin(),pri[j]);
    }
  }
}

struct BIT{
  int a[maxk_pri];
  void add(int pos,int x){
    for(int i = pos;i <= pri_num;i += i & -i) a[i] += x;
  }
  int qsum(int pos){
    int res = 0;
    for(int i = pos;i;i -= i & -i) res += a[i];
    return res;
  }
}cnt;
int V,fct_node[maxk],stk_tp,dep[maxV],stk[maxV];// stknode_id.
// dep[root] = 0.
vector <P> chi[maxV];// to,cst.
void virtual_tree(int n){// crucial nodes: 1! ~ n!
  fct_node[0] = fct_node[1] = ++V;
  stk[++stk_tp] = V;
  int tot = 0;// total number of prime factors
  for(int i = 2;i <= n;i++){
    int x = i, lca_dep = tot - cnt.qsum(pid[factor[i].back()] - 1);
    for(int j = 0;j < (int)factor[i].size();j++){
      int d = factor[i][j], num = 0;
      while(x % d == 0) x /= d, num++;
      cnt.add(pid[d],num);
      tot += num;
    }
    if(lca_dep != dep[stk[stk_tp]]){
      while(dep[stk[stk_tp - 1]] > lca_dep){
        chi[stk[stk_tp - 1]].push_back(mp(
          stk[stk_tp],dep[stk[stk_tp]] - dep[stk[stk_tp - 1]]));
        stk_tp--;
      }
      if(dep[stk[stk_tp - 1]] == lca_dep){
        chi[stk[stk_tp - 1]].push_back(mp(
          stk[stk_tp],dep[stk[stk_tp]] - dep[stk[stk_tp - 1]]));
        stk_tp--;
      }else{
        chi[++V].push_back(mp(stk[stk_tp],dep[stk[stk_tp]] - lca_dep));
        stk[stk_tp] = V;
        dep[V] = lca_dep;
      }
    }
    stk[++stk_tp] = ++V;
    dep[V] = tot;
    fct_node[i] = V;
  }
  for(int i = 1;i < stk_tp;i++){
    chi[stk[i]].push_back(mp(stk[i + 1],dep[stk[i + 1]] - dep[stk[i]]));
  }
}
int n,siz[maxV];
void calc_siz(int u){
  for(int i = 0;i < (int)chi[u].size();i++){
    int v = chi[u][i].first;
    calc_siz(v);
    siz[u] += siz[v];
  }
}
ll ans;
int fin_cen(int u){
  for(int i = 0;i < (int)chi[u].size();i++){
    int v = chi[u][i].first;
    if(siz[v] * 2 > n){
      ans -= ll(siz[v] - n + siz[v]) * chi[u][i].second;
      return fin_cen(v);
    }
  }
  return u;
}
int main(){
  prime_sieve(5000);
  virtual_tree(5000);
  n = getint();
  for(int i = 1;i <= n;i++){
    int k = getint();
    siz[fct_node[k]]++;
    ans += dep[fct_node[k]];
  }
  calc_siz(1);
  fin_cen(1);
  putll(ans,'\n');
  bufo.flush();
  return 0;
}