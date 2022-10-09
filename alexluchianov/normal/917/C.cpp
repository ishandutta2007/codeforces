#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;

int const nmax = 8;
ll const inf = 1000000000000000000;

ll base[1 << nmax];
std::map<int, int> mp;
int c[1 + nmax];

int x, k, n, q;

class Info{
public:
  ll dp[1 << nmax][1 << nmax];
  
  Info(ll val = inf) {
    for(int i = 0; i < (1 << nmax); i++)
      for(int j = 0; j < (1 << nmax); j++)
        dp[i][j] = val;
  }

  Info operator * (Info oth) {
    Info result;
    std::vector<int> masks;
    for(int i = 0; i < (1 << k); i++)
      if(__builtin_popcount(i) == x) 
        masks.push_back(i);
    for(int i = 0; i < masks.size(); i++)
      for(int j = 0; j < masks.size(); j++)
        for(int h = 0; h < masks.size(); h++)
          result.dp[masks[i]][masks[j]] = std::min(result.dp[masks[i]][masks[j]],
                                          dp[masks[i]][masks[h]] + oth.dp[masks[h]][masks[j]]);
    return result;
  }
  void print() {
    for(int i = 0; i < (1 << k); i++) {
      for(int j = 0; j < (1 << k); j++)
        std::cout << dp[i][j] << " ";
      std::cout << '\n';
    }
  }
};

// jump from pos to pos + 1

Info generate(int pos) {
  Info result;
  std::vector<int> masks;
  for(int i = 0; i < (1 << k); i++)
    if(__builtin_popcount(i) == x)
      masks.push_back(i);
  for(int i = 0; i < masks.size(); i++) {
    int start = 0;
    for(int j = 0; j < k; j++)
      if(0 < (masks[i] & (1 << j))) {
        start = j;
        break;
      }
    
    if((masks[i] & 1) == 0)
      result.dp[masks[i]][masks[i] / 2] = std::min(result.dp[masks[i]][masks[i] / 2], 0LL);

    for(int j = start + 1; j <= k; j++) {
      if((masks[i] & (1 << j)) == 0) {
        int mask2 = ((masks[i] ^ (1 << start) ^ (1 << j))>>1);
        result.dp[masks[i]][mask2] = std::min(result.dp[masks[i]][mask2], 1LL * c[j - start] + mp[pos + j]);
      }
    }
  }
  return result;
}

int const sigma = 30;
Info empt[1 + sigma];

void lgpow(Info &base, int target) {
  for(int i = sigma - 1; 0 <= i; i--)
    if((1 << i) <= target) {
      target -= (1 << i);
      base = base * empt[i];
    }
}

int main() {
  std::cin >> x >> k >> n >> q;

  std::vector<int> spec;
  for(int i = 1;i <= k; i++)
    std::cin >> c[i];
  
  empt[0] = generate(1);
  for(int i = 1; i < sigma; i++)
    empt[i] = empt[i - 1] * empt[i - 1];
  
  for(int i = 1; i <= q; i++) {
    int pos, val;
    std::cin >> pos >> val;
    mp[pos] = val;
    for(int j = std::max(1, pos - k); j <= pos; j++)
      spec.push_back(j);
  }

  std::sort(spec.begin(), spec.end());
  spec.erase(std::unique(spec.begin(), spec.end()), spec.end());
  Info base;
  base.dp[(1 << x) - 1][(1 << x) - 1] = 0;
  int last = 1;

  for(int i = 0; i < spec.size() && spec[i] <= n - x; i++) {
    if(last < spec[i]) {
      lgpow(base, spec[i] - last);
    }
    base = base * generate(spec[i]);
    last = spec[i] + 1;
  }
  lgpow(base, n - x - last + 1);
  std::cout << base.dp[(1 << x) - 1][(1 << x) - 1] << '\n';
  return 0;
}