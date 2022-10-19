#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, K;
char s[MAXN];

void load() {
  scanf("%d%d%s", &N, &K, s);
}

int solve() {
  s[N] = 'W';
  vector <int> blocks;
  int last = -1, cnt = 0;
  for (int i = 0; i <= N; i++) 
    if (s[i] == 'W') {
      cnt += (i < N) && (!i || s[i - 1] == 'L');
      if (i > last + 1)
        blocks.push_back(i - last - 1);
      last = i;
    }
  if (!cnt)
    return max(2 * K - 1, 0);
  int lost = accumulate(blocks.begin(), blocks.end(), 0);
  int won = N - lost;
  K = min(K, lost);
  won += K;
  if (s[0] == 'L' && !blocks.empty())
    blocks.erase(blocks.begin());
  if (s[N - 1] == 'L' && !blocks.empty())
    blocks.pop_back();
  sort(blocks.begin(), blocks.end());
  for (auto it : blocks) {
    if (K < it)
      break;
    K -= it;
    cnt--;
  }
  return 2 * won - cnt;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}