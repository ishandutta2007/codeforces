#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int N;
int perm[MAXN];
vector <vector <vector <int>>> partitions[10];

void init() {
  partitions[0].push_back({vector <int> ()});
  for (int n = 1; n < 10; n++) 
    for (int mask = 0; mask < 1 << n - 1; mask++) {
      vector <int> elem{0}, rest;
      for (int i = 0; i < n - 1; i++)
        if (mask >> i & 1)
          elem.push_back(i + 1);
        else
          rest.push_back(i + 1);
      for (auto part : partitions[rest.size()]) {
        vector <vector <int>> part1 = {elem};
        for (auto elem1 : part) {
          vector <int> elem2;
          for (auto it : elem1)
            elem2.push_back(rest[it]);
          if (!elem2.empty())
            part1.push_back(elem2);
        }
        partitions[n].push_back(part1);
      }
    }
}

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", perm + i);
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int pot(int x, int y) {
  int res = 1;
  while (y--)
    res = mul(res, x);
  return res;
}

void solve() {
  vector <int> cycles;
  vector <bool> bio(N + 1);
  int twos = (3 - N % 3) % 3;
  int threes = (N - 2 * twos) / 3;
  for (int i = 1; i <= N; i++) 
    if (!bio[i]) {
      int len = 0;
      for (int x = i; !bio[x]; x = perm[x]) {
        bio[x] = true;
        len++;
      }
      cycles.push_back(len);
    }
  vector <vector <int>> gps(3);
  for (auto it : cycles)
    gps[it % 3].push_back(it);
  for (int i = 0; i < 3; i++) 
    sort(gps[i].begin(), gps[i].end(), greater <int> ());
  int moves = 0, mini = 2 * N;
  auto pairing = [&]() {
    gps[0].push_back(gps[1].back() + gps[2].back());
    gps[1].pop_back();
    gps[2].pop_back(); 
    moves++;
  };
  auto at_least = [&](int bound) {
    return gps[1].size() >= bound && gps[2].size() >= bound;
  };
  while (at_least(5)) 
    pairing(); 
  while (1) {
    int triples = 0;
    vector <vector <int>> rem = gps;
    for (int i = 1; i < 3; i++)
      for (; rem[i].size() >= 5; triples++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
          sum += rem[i].back();
          rem[i].pop_back();
        }
        rem[0].push_back(sum);
      }
    rem[1].insert(rem[1].end(), rem[2].begin(), rem[2].end());
    if (!rem[0].empty()) {
      rem[1].push_back(rem[0].back());
      rem[0].pop_back();
    }
    int best = 0;
    int sz = rem[1].size();
    for (auto part : partitions[sz]) {
      vector <int> tmp;
      for (auto elem : part) {
        int sum = 0;
        for (auto it : elem)
          sum += rem[1][it];
        if (sum % 3)
          tmp.push_back(sum);
      }
      int curr = 2 * (int)part.size();
      if (N % 3 == 1) {
        if (tmp.size() == 2)
          best = max(best, curr);
        else if (tmp.size() == 1 && tmp[0] >= 4)
          best = max(best, curr + 1);
      }
      else if (tmp.size() <= twos)
        best = max(best, curr);
    }
    mini = min(mini, moves + 2 * triples + sz - best - (int)rem[0].size());
    if (!at_least(1))
      break;
    pairing();
  }
  printf("%d %d\n", mul(pot(2, twos), pot(3, threes)), twos + threes + mini);
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}