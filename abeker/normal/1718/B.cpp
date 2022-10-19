#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 50;

ll fib[MAX];

void init() {
  fib[1] = 1;
  fib[2] = 2;
  for (int i = 3; i < MAX; i++)
    fib[i] = fib[i - 1] + fib[i - 2];
}

vector <int> zeckendorf(int x) {
  vector <int> res;
  for (int i = MAX - 1; i; i--)
    if (fib[i] <= x) {
      res.push_back(i);
      x -= fib[i];
    }
  reverse(res.begin(), res.end());
  assert(!x);
  return res;
}

bool solve() {
  int K;
  scanf("%d", &K);
  if (K == 1) {
    int tmp;
    scanf("%d", &tmp);
    return tmp == 1;
  }
  vector <int> occ(K);
  vector <int> freq(MAX);
  vector <int> bad = {MAX};
  vector <vector <int>> repr(K), alt(K, bad);
  for (int i = 0; i < K; i++) {
    scanf("%d", &occ[i]);
    repr[i] = zeckendorf(occ[i]);
    if (occ[i] >= 3) {
      alt[i] = zeckendorf(occ[i] - 3);
      if (!alt[i].empty() && alt[i][0] < 4)
        alt[i] = bad;
      else {
        alt[i].insert(alt[i].begin(), 2);
        alt[i].insert(alt[i].begin(), 1);
      }
    }
    for (auto it : repr[i])
      freq[it]++;
  }
  auto check = [&]() {
    if (freq[1] != 2)
      return false;
    for (int i = 2; i < MAX; i++) {
      if (freq[i] > 1)
        return false;
      if (freq[i] && !freq[i - 1])
        return false;
    }
    return true;
  };
  if (check())
    return true;
  for (int i = 0; i < K; i++)
    if (alt[i] != bad) {
      for (auto it : repr[i])
        freq[it]--;
      for (auto it : alt[i])
        freq[it]++;
      if (check())
        return true;
      for (auto it : alt[i])
        freq[it]--;
      for (auto it : repr[i])
        freq[it]++;
    }
  return false;
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while (tc--)
    puts(solve() ? "YES" : "NO");
  return 0;
}