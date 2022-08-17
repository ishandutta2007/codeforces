#include <iostream>
#include <vector>

#define int long long

const int ALPH = 26;
const int MAXN = 100005;
const int INF = 1'000'000'000'000;

int bit[MAXN];

void upd(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&(-x);
  }
}

int sum(int x) {
  int ret = 0;
  x += 1;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> app[ALPH];
    int it[ALPH];
    
    for(int i = 0; i < ALPH; i++) {
      it[i] = 0;
    }

    for(int i = 0; i <= n; i++)
      bit[i] = 0;

    for(int i = 0; i < n; i++) {
      char c;
      std::cin >> c;
      app[c-'a'].push_back(i);
      upd(i, 1);
    }

    std::string s;
    std::cin >> s;

    int already = 0;
    int ans = INF;

    for(int i = 0; i < n; i++) {
      int ch = s[i]-'a';
      for(int j = 0; j < ch; j++) {
        if(it[j] < app[j].size()) {
          ans = std::min(ans, already + sum(app[j][it[j]]) - 1);
        }
      }

      if(it[ch] < app[ch].size()) {
        upd(app[ch][it[ch]], -1);
        already += sum(app[ch][it[ch]]);
        it[ch]++;
      }
      else
        break;
    }

    std::cout << (ans == INF ? -1 : ans) << std::endl;
  }

  return 0;
}