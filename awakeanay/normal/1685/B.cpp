#include <iostream>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::string s;
    std::cin >> s;

    int n = s.length();
    int ct[2] = {0, 0};
    for(int i = 0; i < n; i++) {
      ct[s[i] == 'A']++;
    }

    if(ct[1] != a + c + d) {
      std::cout << "NO" << std::endl;
      continue;
    }

    std::set<std::pair<int, int> > st[2];
    int cur = 0;
    int ex = 0;
    int cx = 0;
    int dx = 0;

    while(cur < n) {
      int id = cur;
      while(cur+1 < n && s[cur] != s[cur+1])
        cur++;
      int len = cur-id+1;
      if(len%2) {
        ex += len/2;
      }
      else {
        int u = s[id] == 'A';
        st[u].insert({len/2, id});
        if(u)
          cx += len/2;
        else
          dx += len/2;
      }
      cur++;
    }

    bool poss = false;
    if(c - std::min(c, cx) + d - std::min(d, dx) <= ex)
      poss = true;

    if(cx > c) {
      int extra = cx-c;
      for(int i = 0; i < extra; i++) {
        if(st[1].empty())
          break;
        auto v = *st[1].rbegin();
        cx -= v.first;
        ex += v.first-1;
        st[1].erase(v);
        if(c - std::min(c, cx) + d - std::min(d, dx) <= ex)
          poss = true;
      }
    }
    //std::cout << cx << " " << dx << " " << ex << std::endl;
    if(dx > d) {
      int extra = dx-d;
      for(int i = 0; i < extra; i++) {
        if(st[0].empty())
          break;
        auto v = *st[0].rbegin();
        dx -= v.first;
        ex += v.first-1;
        st[0].erase(v);
        if(c - std::min(c, cx) + d - std::min(d, dx) <= ex)
          poss = true;
      }
    }


    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}