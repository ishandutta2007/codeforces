#include <iostream>
#include <algorithm>
#include <set>

#define int long long

const int MAXN = 200005;

int freq[MAXN];

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int m[n], k[n];
  for(int i = 0; i < n; i++)
    std::cin >> m[i] >> k[i];

  std::pair<int, int> best = {0, 1};
  int ft = -1;

  for(int t = 1; t <= 20; t++) {
    for(int i = 0; i < n; i++)
      freq[m[i]] += std::min(t, k[i]);

    std::set<std::pair<int, int> > avail;
    for(int i = 0; i < MAXN; i++) {
      avail.insert({freq[i], i});
      if(avail.size() > t)
        avail.erase(avail.begin());
    }

    if(avail.size() == t) {
      std::pair<int, int> cur = {0, t};
      for(auto j : avail)
        cur.first += j.first;

      int gd = gcd(cur.first, cur.second);
      cur.first /= gd;
      cur.second /= gd;

      if(cur.first*best.second > cur.second*best.first) {
        ft = t;
        best = cur;
      }
    }

    if(t != 20) 
      for(int i = 0; i < n; i++)
        freq[m[i]] = 0;
  }

  std::sort(freq, freq+MAXN);
  std::reverse(freq, freq+MAXN);

  int pre = 0;
  for(int i = 0; i < 20; i++) {
    pre += freq[i];
    freq[i] = 0;
  }

  for(int t = 21; t <= MAXN; t++) {
    pre += freq[t-1];
    freq[t-1] = 0;

    std::pair<int, int> cur = {pre, t};

    int gd = gcd(cur.first, cur.second);
    cur.first /= gd;
    cur.second /= gd;

    if(cur.first*best.second > cur.second*best.first) {
      ft = t;
      best = cur;
    }
  }

  for(int i = 0; i < n; i++)
    freq[m[i]] += std::min(ft, k[i]);

  std::set<std::pair<int, int> > avail;
  for(int i = 0; i < MAXN; i++) {
    avail.insert({freq[i], i});
    if(avail.size() > ft)
      avail.erase(avail.begin());
  }

  std::cout << ft << std::endl;
  for(auto j : avail)
    std::cout << j.second << " ";
  std::cout << std::endl;

  return 0;
}