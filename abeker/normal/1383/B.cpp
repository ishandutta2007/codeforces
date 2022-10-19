#include <bits/stdc++.h>
using namespace std;

const int LOG = 30;

string solve() {
  int N;
  vector <int> cnt(LOG);
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < LOG; j++)
      cnt[j] += x >> j & 1;
  }
  for (int i = LOG - 1; i >= 0; i--)
    if (cnt[i] % 2)
      return (N - cnt[i]) % 2 || cnt[i] % 4 == 1 ? "WIN" : "LOSE";
  return "DRAW";
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) 
    puts(solve().c_str());
  return 0;
}