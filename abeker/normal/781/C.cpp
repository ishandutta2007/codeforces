#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 200005;

int N, M, K;
vector <int> E[MAXN];
bool bio[MAXN];
vector <int> all;
int cnt;

void load() {
  scanf("%d%d%d", &N, &M, &K);
  while (M--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x != y) {
      E[x].push_back(y);
      E[y].push_back(x);
    }
  }
}

void dfs(int x) {
  bio[x] = true;
  all.push_back(x);
  for (int i = 0; i < E[x].size(); i++) {
    int nxt = E[x][i];
    if (bio[nxt])
      continue;
    dfs(nxt);
    all.push_back(x);
  }
}

void output(vector <int> v) {
  cnt++;
  printf("%d ", v.size());
  for (int i = 0; i < v.size(); i++)
    printf("%d ", v[i]);
  puts("");
}

void solve() {
  dfs(1); 
  
  vector <int> curr;
  int limit = (2 * N + K - 1) / K;
  for (int i = 0; i < all.size(); i++) {
    curr.push_back(all[i]);
    if (curr.size() == limit) {
      output(curr);
      curr.clear();
    }
  }
  if (!curr.empty())
    output(curr);
    
  for (int i = 0; i < K - cnt; i++)
    puts("1 1");
}

int main() {
  load();
  solve();
  return 0;
}