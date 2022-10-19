#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> a;
vector <int> ans;

void load() {
  scanf("%d", &N);
  a.resize(N);
  for (int i = 0; i < N; i++)
    scanf("%d", &a[i]);
}

int mex() {
  vector <bool> bio(N + 1);
  for (int i = 0; i < N; i++)
    bio[a[i]] = true;
  for (int i = 0; i <= N; i++)
    if (!bio[i]) 
      return i;
  assert(false);
}

void apply(int x) {
  ans.push_back(x);
  a[x] = mex();
}

void solve() {
  ans.clear();
  while (1) {
    int pos = mex();
    if (pos == N)
      break;
    apply(pos);
  }
  
  vector <int> memo = a;
  vector <bool> visited(N);
  for (int i = 0; i < N; i++) 
    if (memo[i] != i && !visited[i]) { 
      for (int x = i; !visited[x]; x = memo[x]) {
        visited[x] = true;
        apply(x);
      }
      apply(i);
    }
  
  printf("%d\n", ans.size());
  for (auto it : ans) 
    printf("%d ", it + 1);
  puts("");
}

void check() {
  assert(ans.size() <= 2 * N);
  for (int i = 1; i < N; i++)
    assert(a[i - 1] <= a[i]);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
    check();
  }
  return 0;
}