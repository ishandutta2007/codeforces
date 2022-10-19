#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;

int N, M;
int inv;
vector <pii> E[MAXN], ch[MAXN];
int depth[MAXN];
int pot1[MAXN], pot2[MAXN];
int num1[MAXN], num2[MAXN];
int dad[MAXN];
map <int, int> cnt1[MAXN];
map <int, int> cnt2[MAXN]; 
ll sol;

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i < N; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u++; v++;
    E[u].push_back(pii(v, w));
    E[v].push_back(pii(u, w));
  }
}

inline int add(int x, int y) {
  x += y;
  if (x >= M) x -= M;
  else if (x < 0) x += M;
  return x;
}

inline int mul(int x, int y) {
  return (ll)x * y % M;
}

void dfs(int x, int p, int d, int z) {
  num1[x] = add(num1[p], mul(d ? pot1[d - 1] : 0, z));
  num2[x] = add(num2[p], mul(d ? pot2[d - 1] : 0, z)); 
  depth[x] = d;
  for (int i = 0; i < E[x].size(); i++)
    if (E[x][i].first != p) {
      dfs(E[x][i].first, x, d + 1, E[x][i].second);
      ch[x].push_back(E[x][i]);
    }
}

int find(int x) {
  return x == dad[x] ? x : dad[x] = find(dad[x]);
}

void join(int x, int y, int node) {
  x = find(x);
  y = find(y);
  if (cnt1[x].size() > cnt1[y].size()) 
    swap(x, y);
  dad[x] = y;
  for (auto it : cnt1[x]) {
    int tmp = add(0, -mul(add(it.first, -num1[node]), pot2[depth[node]]));
    sol += (ll)cnt2[y][add(num2[node], mul(mul(tmp, 10), pot2[depth[node]]))] * it.second;
  }
  for (auto it : cnt2[x]) {
    int tmp = add(0, -mul(mul(add(it.first, -num2[node]), pot1[depth[node]]), inv));
    sol += (ll)cnt1[y][add(num1[node], mul(tmp, pot1[depth[node]]))] * it.second;
  }
  for (auto it : cnt1[x])
    cnt1[y][it.first] += it.second;
  for (auto it : cnt2[x])
    cnt2[y][it.first] += it.second;
}

void calc(int x, int p) {
  for (int i = 0; i < ch[x].size(); i++) {
    calc(ch[x][i].first, x);
    if (i) join(ch[x][i - 1].first, ch[x][i].first, x);
  } 
  if (!ch[x].empty()) 
    join(x, ch[x].back().first, x);
}

ll solve() {
  if (M == 1) 
    return (ll)N * (N - 1);
  ll i = 1;
  for (; i % 10; i += M);
  inv = (int)(i / 10);
  
  pot1[0] = pot2[0] = 1;
  for (int i = 1; i <= N; i++) {
    pot1[i] = mul(pot1[i - 1], 10);
    pot2[i] = mul(pot2[i - 1], inv);
  }
  
  dfs(1, 0, 0, 0); 
  
  for (int i = 1; i <= N; i++) {
    dad[i] = i;
    cnt1[i][num1[i]]++;
    cnt2[i][num2[i]]++;
  }
  
  calc(1, 0);
  
  return sol;
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}