#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 1005
#define maxV 105
#define maxl 15 // l: |s_i|

using namespace std;
typedef long long ll;
const int mod = 1000000009;

struct node{
  int chi[4], fail, dep, edDep;
  node(){
    memset(chi, 0, sizeof(chi));
    dep = fail = edDep = 0;
  }
}a[maxV]; int V;
namespace acAuto{
  void init(){
    V = 1;
  }
  void ins(int* s, int n){
    int u = 1;
    for(int i = 1;i <= n;i++){
      if(!a[u].chi[s[i]]){
        a[u].chi[s[i]] = ++V;
        a[V].dep = i;
      }
      u = a[u].chi[s[i]];
    }
    a[u].edDep = n;
  }
  void build(){
    queue<int> que;
    que.push(1);
    while(!que.empty()){
      int u = que.front();
      que.pop();
      for(int i = 0;i < 4;i++){
        int v = a[u].chi[i], f = a[u].fail;
        if(v){
          if(f) a[v].fail = a[f].chi[i];
          else a[v].fail = 1;
          a[v].edDep = max(a[v].edDep, a[a[v].fail].edDep);
          que.push(v);
        }else{
          if(f) a[u].chi[i] = a[f].chi[i];
          else a[u].chi[i] = 1;
        }
      }
    }
  }
}
int idx[135], n, m, f[maxn][maxV][maxl], sidx[maxl];
char s[maxl];

int main(){
  idx['A'] = 0, idx['C'] = 1, idx['G'] = 2, idx['T'] = 3;
  acAuto::init();
  scanf("%d%d", &n, &m);
  for(int i = 1;i <= m;i++){
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    for(int j = 1;j <= l;j++) sidx[j] = idx[(int)s[j]];
    acAuto::ins(sidx, l);
  }
  
//  for(int i = 1;i <= V;i++){
//    cout << i << ": " << a[i].chi[0] << " " << a[i].chi[1] <<
//     " " << a[i].chi[2] << " " << a[i].chi[3] << " " << a[i].dep << " "
//     << a[i].ed << endl;
//  }
//  cout << endl;
//  system("pause");
  
  acAuto::build();
  
//  for(int i = 1;i <= V;i++){
//    cout << i << ": " << a[i].chi[0] << " " << a[i].chi[1] <<
//     " " << a[i].chi[2] << " " << a[i].chi[3] << endl;
//  }
//  cout << endl;
//  system("pause");
  
  f[0][1][0] = 1;
  for(int i = 0;i < n;i++){
    for(int u = 1;u <= V;u++){
      for(int j = 0;j <= a[u].dep;j++){
        for(int k = 0;k < 4;k++){
          int v = a[u].chi[k];
          if(a[v].dep >= j + 1){
            (f[i + 1][v][a[v].edDep >= j + 1 ? 0 : j + 1] += f[i][u][j]) %= mod;
          }
        }
      }
    }
  }
  int ans = 0;
  for(int u = 1;u <= V;u++) (ans += f[n][u][0]) %= mod;
  printf("%d\n", ans);
  return 0;
}