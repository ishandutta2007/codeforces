#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N;
char s[MAXN];
vector <int> todo[MAXN];
int dad[MAXN], rnk[MAXN], maks[MAXN];
bool bad[MAXN];

void load() {
  scanf("%d%s", &N, s + 1);
}

int find(int x) {
  return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  if (rnk[x] > rnk[y])
    swap(x, y);
  dad[x] = y;
  rnk[y] += rnk[x] == rnk[y];
  maks[y] = max(maks[y], maks[x]);
}

int greedy(int x) {
  int res = 0, pos = 0;
  while (1) {
    pos += x;
    if (pos > N)
      break;
    if (bad[pos])
      pos = maks[find(pos)] + 1;
    if (pos > N)
      break;
    res++;
  }
  return res;
}

void solve() {
  vector <int> lst(2);
  for (int i = 1; i <= N; i++) {
    if (s[i] != '?')
      lst[s[i] - '0'] = i;
    todo[i - *min_element(lst.begin(), lst.end())].push_back(i);
    dad[i] = maks[i] = i;
  } 
  for (int i = 1; i <= N; i++) {
    printf("%d ", greedy(i));
    for (auto it : todo[i]) {
      bad[it] = true;
      for (auto neigh : {it - 1, it + 1})
        if (bad[neigh])
          join(it, neigh);
    }
  }
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}