/*
 tourist 
authorAlex_Wei
powered by c++14
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int S = 26;
char s[N], t[N];
int n, k, cnt = 1, las = 1, le, son[N][S];
int fa[N], len[N], ed[N];
int buc[N], id[N];
queue<int> q;
void insert(int it) {
  int cur = ++cnt, p = las;
  las = cur, len[cur] = len[p] + 1, ed[cur] = 1;
  while(!son[p][it]) son[p][it] = cur, p = fa[p];
  if(!p) return fa[cur] = 1, void();
  int q = son[p][it];
  if(len[p] + 1 == len[q]) return fa[cur] = q, void();
  int cl = ++cnt;
  memcpy(son[cl], son[q], S << 2);
  fa[cl] = fa[q], fa[q] = fa[cur] = cl, len[cl] = len[p] + 1;
  while(son[p][it] == q) son[p][it] = cl, p = fa[p];
}
long long f[N];
long long dfs(int id) {
  if(!id) return 0;
  if(f[id]) return f[id];
  for(int i = 0; i < S; i++) f[id] += dfs(son[id][i]);
  return f[id] += ed[id]; // + -> +=
}
void find(int id, int res) {
  if(res <= ed[id]) cout << t + 1 << endl, exit(0);
  res -= ed[id];
  for(int i = 0; i < S; i++) {
    if(res <= f[son[id][i]]) t[++le] = i + 'a', find(son[id][i], res);
    else res -= f[son[id][i]];
  }
}
int main() {
  // freopen("1.in", "r", stdin);
  cin >> s + 1 >> k, n = strlen(s + 1);
  for(int i = 1; i <= n; i++) insert(s[i] - 'a');
  for(int i = 1; i <= cnt; i++) buc[len[i]]++;
  for(int i = 1; i <= n; i++) buc[i] += buc[i - 1];
  for(int i = cnt; i; i--) id[buc[len[i]]--] = i;
  for(int i = cnt; i; i--) ed[fa[id[i]]] += ed[id[i]];
  ed[1] = 0, dfs(1), find(1, k);
  puts("No such line.");
  return 0;
}
/*
2022/5/15
start coding at 14:30
finish coding at 14:46

*/