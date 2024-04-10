#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int query(std::vector<int> s) {
  if(s.size() > 0) {
    std::cout << "? " << s.size() << " ";
    for(int j : s)
      std::cout << j << " ";
    std::cout << std::endl;
    int ret;
    std::cin >> ret;
    return ret;
  }
  return 0;
}

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> mark(n, 0);

    std::vector<int> s[k];
    std::vector<int> all;
    for(int i = 0; i < k; i++) {
      int c;
      std::cin >> c;
      while(c--) {
        int x;
        std::cin >> x;
        s[i].push_back(x);
        all.push_back(x);
        mark[x-1] = 1;
      }
    }

    int max = query(all);

    int l = 0, r = k-1;
    while(l < r) {
      int m = (l+r)/2;
      
      std::vector<int> q;
      for(int i = l; i <= m; i++) {
        q.insert(q.end(), s[i].begin(), s[i].end());
      }

      bool check = (query(q) == max);
      
      if(check)
        r = m;
      else
        l = m+1;
    }

    std::vector<int> q;
    int smax = 0;
    for(int i = 0; i < k; i++) {
      if(i != l)
        q.insert(q.end(), s[i].begin(), s[i].end());
    }
    for(int i = 0; i < n; i++)
      if(!mark[i]) q.push_back(i+1);

    smax = query(q);

    std::cout << "! ";
    for(int i = 0; i < k; i++) {
      if(i != l)
        std::cout << max << " ";
      else
        std::cout << smax << " ";
    }

    std::cout << std::endl;
    std::string temp;
    std::cin >> temp;
  }
  
  return 0;
}