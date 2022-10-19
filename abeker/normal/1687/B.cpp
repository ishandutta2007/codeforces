#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int N, M;

int ask(const vector <int> &edges) {
  vector <int> in(M);
  for (auto it : edges)
    in[it] = 1;
  printf("? ");
  for (int i = 0; i < M; i++)
    printf("%d", in[i]);
  puts("");
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}

int main() {
  scanf("%d%d", &N, &M);
  vector <pii> sorted;
  for (int i = 0; i < M; i++)
    sorted.push_back({ask({i}), i});
  sort(sorted.begin(), sorted.end());
  int sum = 0;
  vector <int> taken;
  for (auto it : sorted) {
    sum += it.first;
    taken.push_back(it.second);
    if (ask(taken) != sum) {
      sum -= it.first;
      taken.pop_back();
    }
  }
  printf("! %d\n", sum);
  fflush(stdout);
  return 0;
}