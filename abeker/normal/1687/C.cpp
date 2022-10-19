#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N, M;
int a[MAXN], b[MAXN];
int l[MAXN], r[MAXN];
ll pref[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", b + i);
  for (int i = 0; i < M; i++)
    scanf("%d%d", l + i, r + i);
}

bool solve() {
  a[N + 1] = 0;
  for (int i = 1; i <= N; i++) {
    a[i] -= b[i];
    pref[i] = pref[i - 1] + a[i];
  }
  vector <int> covered(N + 2);
  for (int i = 0; i < M; i++) {
    covered[l[i]]++;
    covered[r[i] + 1]--;
  }
  int last = 0;
  map <ll, bool> good;
  for (int i = 1; i <= N + 1; i++) {
    covered[i] += covered[i - 1];
    if (!covered[i]) {
      if (a[i])
        return false;
      if (!last)
        continue;
      if (pref[i - 1] != pref[last - 1])
        return false;
      good[pref[i - 1]] = true;
    }
    else if (!last)
      last = i;
  }
  vector <vector <int>> queries(N + 1);
  for (int i = 0; i < M; i++) {
    queries[l[i] - 1].push_back(i);
    queries[r[i]].push_back(i);
  }
  queue <int> q;
  set <int> bad;
  vector <bool> bio(M);
  for (int i = 0; i <= N; i++)
    bad.insert(i);
  auto update = [&](int pos) {
    bad.erase(pos);
    for (auto it : queries[pos])
      if (!bio[it] && !bad.count((l[it] - 1) ^ r[it] ^ pos))
        q.push(it);
  };
  for (int i = 0; i <= N; i++)
    if (good[pref[i]]) 
      update(i);
  while (!q.empty()) {
    int x = q.front();
    bio[x] = true;
    q.pop();
    while (!bad.empty()) {
      auto it = bad.lower_bound(l[x]);
      if (it == bad.end() || *it > r[x])
        break;
      update(*it);
    }
  }
  for (int i = 0; i < M; i++)
    if (!bio[i])
      return false;
  return true;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}