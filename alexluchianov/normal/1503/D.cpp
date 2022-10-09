#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 200000;

std::pair<int, int> v[5 + nmax];

bool compare(std::pair<int,int> f1, std::pair<int,int> f2) {
  return std::min(f1.first, f1.second) < std::min(f2.first, f2.second);
}

int lower(std::pair<int,int> f1) {
  return std::min(f1.first, f1.second);
}

int upper(std::pair<int,int> f1) {
  return std::max(f1.first, f1.second);
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i].first >> v[i].second;
    if(std::max(v[i].first, v[i].second) <= n) {
      std::cout << -1;
      return 0;
    }
  }
  std::sort(v + 1, v + n + 1, compare);
  for(int i = 1;i <= n; i++)
    assert(lower(v[i]) == i);

  std::vector<int> pref(2 + n), suff(2 + n);
  pref[0] = nmax * 3;
  for(int i = 1;i <= n; i++)
    pref[i] = std::min(pref[i - 1], upper(v[i]));
  for(int i = n; 1 <= i; i--)
    suff[i] = std::max(suff[i + 1], upper(v[i]));
  
  int result1 = 0, result2 = 0;
  std::vector<int> seqs[2];
  
  int answer = 0;

  for(int i = 1;i <= n; i++) {
    if(pref[i - 1] < upper(v[i])) {
      seqs[1].push_back(upper(v[i]));
      result2 += (v[i].first < v[i].second);
      result1 += !(v[i].first < v[i].second);

    } else if(upper(v[i]) < suff[i + 1]) {
      seqs[0].push_back(upper(v[i]));
      result1 += (v[i].first < v[i].second);
      result2 += !(v[i].first < v[i].second);
    }
    
    if(pref[i] >= suff[i + 1]) {
      answer += std::min(result1, result2);
      result1 = result2 = 0;
    }
  }

  std::reverse(seqs[0].begin(), seqs[0].end());
  std::reverse(seqs[1].begin(), seqs[1].end());
  
  if(is_sorted(seqs[0].begin(), seqs[0].end()) && is_sorted(seqs[1].begin(), seqs[1].end()))
    std::cout << answer << '\n';
  else
    std::cout << -1 << '\n';
  return 0;
}