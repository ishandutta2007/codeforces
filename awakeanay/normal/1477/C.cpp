#include <vector>
#include <algorithm>
#include <iostream>

#define int long long

bool check(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c) {
  std::pair<int, int> ba = {a.first-b.first, a.second-b.second};
  std::pair<int, int> bc = {c.first-b.first, c.second-b.second};

  return ba.first*bc.first + ba.second*bc.second > 0;
}

signed main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int> > ans;
  std::vector<int> out;
  for(int i = 0; i < 2; i++) {
    int x, y;
    std::cin >> x >> y;
    ans.push_back({x, y});
    out.push_back(i);
  }

  for(int i = 2; i < n; i++) {
    std::pair<int, int> cur;
    std::cin >> cur.first >> cur.second;

    int put = -1;
    int k = ans.size();
    for(int j = 0; j <= ans.size(); j++) {
      int poss = true;
      if(j+1 < k) {
        poss &= check(cur, ans[j], ans[j+1]);
      }
      if(j > 0 && j < k) {
        poss &= check(ans[j-1], cur, ans[j]);
      }
      if(j > 1) {
        poss &= check(ans[j-2], ans[j-1], cur);
      }

      if(poss) {
        put = j;
        break;
      }
    }

    ans.insert(ans.begin() + put, cur);
    out.insert(out.begin() + put, i);
  }

  for(int j : out)
    std::cout << j + 1 << " ";
  std::cout << std::endl;

  return 0;
}