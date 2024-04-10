#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;

int N, M;
map <int, int> freq;

void load() {
  scanf("%d%d", &N, &M);
  freq.clear();
  for (int i = 0; i < N; i++) {  
    int x;
    scanf("%d", &x);
    freq[x]++;
  }
}

ll solve() {
  vector <int> values, freqs;
  vector <vector <int>> by_freq(N + 1);
  map <int, int> idx;
  for (auto it : freq) {
    idx[it.first] = values.size();
    by_freq[it.second].push_back(values.size());
    values.push_back(it.first);
    freqs.push_back(it.second);
  }
  vector <vector <int>> adj(N);
  while (M--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = idx[x];
    y = idx[y];
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector <int> non_empty;
  for (int i = 0; i <= N; i++)
    if (!by_freq[i].empty())
      non_empty.push_back(i);
  ll sol = 0;
  vector <bool> bad(N);
  for (int i = 0; i < values.size(); i++) {
    adj[i].push_back(i);
    for (auto it : adj[i])
      bad[it] = true;
    for (auto it : non_empty) 
      for (int j = (int)by_freq[it].size() - 1; j >= 0; j--) {
        int tmp = by_freq[it][j];
        if (!bad[tmp]) {
          sol = max(sol, (ll)(values[i] + values[tmp]) * (freqs[i] + freqs[tmp]));
          break;
        }
      }
    for (auto it : adj[i])
      bad[it] = false;
  }
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%lld\n", solve());
  }
  return 0;
}