#include <iostream>
#include <vector>

#define int long long

std::vector<std::pair<int, int> > ans;
std::vector<int> reply;

int n;

void query(int x) {
  std::cout << "? " << x << std::endl;
  reply = std::vector<int>(n);
  for(int j = 0; j < n; j++) {
    std::cin >> reply[j];
    if(reply[j] == 1)
      ans.push_back({x, j+1});
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n;

  query(1);
  std::vector<int> cpy = reply;

  std::vector<int> count[2];
  for(int i = 0; i < n; i++) {
    if(reply[i]) {
      count[reply[i]%2].push_back(i+1);
    }
  }

  int opt = 0;
  if(count[1].size() < count[0].size()) {
    opt = 1;
    ans.clear();
  }

  for(int j : count[opt])
    query(j);

  std::cout << "!" << std::endl;
  for(std::pair<int, int> j : ans)
    std::cout << j.first << " " << j.second << std::endl;

  return 0;
}