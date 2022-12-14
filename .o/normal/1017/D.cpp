#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int W[12];
int sumW[1<<12];

int dp[1<<12][1<<12];

int get() {
  static char tmp[15]; scanf("%s", tmp);
  int ret = 0;
  for(int i=0;i<N;i++) {
    ret = ret*2 + (tmp[i] - '0');
  }
  return ret;
}

int freq[1<<12];

vector<pair<int, int>> tb[1<<12];

int main() {
  scanf("%d%d%d", &N, &M ,&Q);
  for(int i = 0; i< N; i++) {
    scanf("%d", &W[i]);
    sumW[1<<(N-i-1)] = W[i];
  }
  for(int mask = 0; mask < (1<<N); mask++) {
    int base = mask & -mask;
    if(mask != base)
      sumW[mask] = sumW[mask ^ base] + sumW[base];
  }

  for(int i = 0; i < M; i++) {
    freq[get()] += 1;
  }

  int all = (1<<N)-1;
  for(int i = 0; i < (1<<N); i++) {
    for(int j = 0; j < (1<<N); j++) {
      if(freq[j] > 0) {
        tb[i].emplace_back(sumW[all ^ (i ^ j)], freq[j]);
      }
    }
    sort(tb[i].begin(), tb[i].end());
    for(int j = 1; j < int(tb[i].size()); j++) {
      tb[i][j].second += tb[i][j-1].second;
    }
  }

  for(int q = 0; q < Q; q++) {
    int v = get();
    int k; scanf("%d", &k);
    auto it = --upper_bound(tb[v].begin(), tb[v].end(), make_pair(k, 19123199));
    printf("%d\n", it == tb[v].end() ? 0 : it->second);
  }
  return 0;
}