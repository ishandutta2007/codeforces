#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;
const int offset = 1 << 17;
const pii spec(0, MAXN);

int N;
vector <int> E[MAXN], ch[MAXN];
int c[MAXN];
int disc[MAXN], fin[MAXN];
int timer = 1;
pii t[2 * offset];

void load() {
  scanf("%d", &N);
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    E[u].push_back(v);
    E[v].push_back(u);
  }
  for (int i = 1; i <= N; i++)
    scanf("%d", c + i);
}

void dfs(int x, int p) {
  disc[x] = timer++;
  for (int i = 0; i < E[x].size(); i++)
    if (E[x][i] != p) {
      dfs(E[x][i], x);
      ch[x].push_back(E[x][i]);
    }
  fin[x] = timer;
}

pii merge(pii l, pii r) {
  return pii(max(l.first, r.first), min(l.second, r.second));
}

pii query(int x, int lo, int hi, int from, int to) {
  if (lo >= to || hi <= from)
    return spec;
  if (lo >= from && hi <= to)
    return t[x];
  int mid = (lo + hi) / 2;
  return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

pii query(int from, int to) {
  return query(1, 0, offset, from, to);
}

bool check(pii p) {
  return p == spec || p.first == p.second;
}

bool good(int x) {
  bool res = check(merge(query(1, disc[x]), query(fin[x], timer)));
  for (int i = 0; i < ch[x].size(); i++)
    res &= check(query(disc[ch[x][i]], fin[ch[x][i]]));
  return res;
}

void solve() {
  dfs(1, 0);  
  
  for (int i = 0; i < offset; i++)
    t[i] = spec;
  for (int i = 1; i <= N; i++)
    t[disc[i] + offset] = pii(c[i], c[i]);
  
  for (int i = offset - 1; i >= 0; i--)
    t[i] = merge(t[2 * i], t[2 * i + 1]);
  
  for (int i = 1; i <= N; i++)
    if (good(i)) {
      puts("YES");
      printf("%d\n", i);
      return;
    }
    
  puts("NO");
}

int main() {
  load();
  solve();
  return 0;
}