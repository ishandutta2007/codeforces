#include <bits/stdc++.h>
using namespace std;

const int L = 10;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int N;
vector <int> ques;
vector <array <int, L + 1>> nxt;
vector <int> sol;

int ask(vector <int> v) {
  for (auto it : v)
    printf("%c", "FT"[it]);
  puts("");
  fflush(stdout);
  int same;
  scanf("%d", &same);
  if (same == N)
    exit(0);
  return N - same;
}

int hamming(int x, int y) {
  return __builtin_popcount(x ^ y);
}

void work(vector <int> pos, int tot) {
  int curr = 0, zeroes = -1;
  vector <int> cands(1 << L);
  iota(cands.begin(), cands.end(), 0);
  for (int iter = 0; cands.size() > 1; iter++) {
    vector <int> tmp(N, 1);
    for (int i = 0; i < L; i++)
      tmp[pos[i]] = ques[curr] >> i & 1;
    int diff = ask(tmp);
    if (!iter)
      zeroes = (diff + tot - L) / 2;
    diff -= zeroes;
    vector <int> good;
    for (auto it : cands)
      if (hamming(it, ques[curr]) == diff)
        good.push_back(it);
    curr = nxt[curr][diff];
    cands = good;
  }
  for (int i = 0; i < L; i++)
    sol[pos[i]] = cands[0] >> i & 1;
}

void gen(vector <int> v) {
  if (v.size() == 1) {
    ques.push_back(v[0]);
    nxt.push_back(array <int, L + 1> ());
    return;
  }
  int mini = (1 << L) + 1, best = -1;
  vector <vector <vector <int>>> groups(1 << L, vector <vector <int>> (L + 1));
  for (int i = 0; i < 1 << L; i++) {
    for (auto it : v)
      groups[i][hamming(it, i)].push_back(it);
    int maks = -1;
    for (int j = 0; j <= L; j++)
      maks = max(maks, (int)groups[i][j].size());
    if (maks < mini) {
      mini = maks;
      best = i;
    }
  }
  int idx = ques.size();
  ques.push_back(best);
  nxt.push_back(array <int, L + 1> ());
  for (int i = 0; i <= L; i++)
    if (!groups[best][i].empty()) {
      nxt[idx][i] = ques.size();
      gen(groups[best][i]);
    }
}

void init() {
  vector <int> all(1 << L);
  iota(all.begin(), all.end(), 0);
  gen(all);
}

void load() {
  scanf("%d", &N);
}

void solve() {
  sol.resize(N);
  int ones = ask(vector <int> (N));
  vector <int> indices(N);
  iota(indices.begin(), indices.end(), 0);
  while (indices.size() >= L) {
    vector <int> curr;
    for (int i = 0; i < L; i++) {
      int tmp = uniform_int_distribution <int> (0, (int)indices.size() - 1)(rng);
      curr.push_back(indices[tmp]);
      indices.erase(indices.begin() + tmp);
    }
    work(curr, N - ones);
  }
  vector <int> memo = sol;
  int rest = ones - accumulate(memo.begin(), memo.end(), 0);
  for (auto it : indices) {
    vector <int> tmp = memo;
    for (auto it1 : indices)
      tmp[it1] = it1 == it;
    sol[it] = ask(tmp) == rest - 1;
  }
  assert(!ask(sol));
}

int main() {
  init();
  load();
  solve();
  return 0;
}