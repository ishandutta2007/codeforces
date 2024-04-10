#include <iostream>
#include <set>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> vis(n, 0);
    int a[n];

    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      a[i]--;
      vis[a[i]]++;
    }

    std::vector<int> ans(n, 0);
    ans[0] = 1;
    for(int i = 0; i < n; i++)
      if(!vis[i])
        ans[0] = false;

    int l = 0, r = n-1;
    int cur = 0;

    std::set<std::pair<int, int> > s;
    for(int i = 0; i < n; i++)
      s.insert({a[i], i});

    for(int i = n-2; i > 0; i--) {
      if(a[l] == cur) {
        s.erase({a[l], l});
        if((*s.begin()).first == cur+1)
          ans[i] = true;
        l++;
      } else if(a[r] == cur) {
        s.erase({a[r], r});
        if((*s.begin()).first == cur+1)
          ans[i] = true;
        r--;
      }
      else
        break;
      
      cur++;
    }

    ans[n-1] = vis[0];
    
    //int first = n;
    //for(int i = 0; i < n; i++)
    //  if(vis[i] > 1) {
    //    first = i;
    //    break;
    //  }

    //if(first < n) {
    //  for(int i = n-2-first; i > 0; i--)
    //    ans[i] = false;

    //  int x = n-first;
    //  std::set<std::pair<int, int> > s;
    //  for(int i = 0; i < x; i++)
    //    s.insert({a[i], i});

    //  std::vector<int> calc;
    //  calc.push_back((*s.begin()).first);

    //  for(int j = x; j < n; j++) {
    //    s.erase({a[j-x], j-x});
    //    s.insert({a[j], j});
    //    calc.push_back((*s.begin()).first);
    //  }

    //  std::vector<int> vis2(calc.size(), 0);
    //  for(int j : calc)
    //    if(j < calc.size())
    //      vis2[j] = true;

    //  int rn = 1;
    //  for(int j : vis2)
    //    if(!j)
    //      rn = false;

    //  ans[n-first-1] = rn;
    //}

    for(int i = 0; i < n; i++)
      std::cout << (ans[i]>0);
    std::cout << std::endl;
  }

  return 0;
}