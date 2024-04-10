#include <iostream>
#include <vector>
#include <bitset>

using ll = long long;

int const sigma = 20;
int const nmax = 100000;
std::vector<int> aint[5 + 4 * nmax];

void update(int node, int from, int to, int x, int y, int val) {
  if(from == x && to == y)
    aint[node].push_back(val);
  else {
    int mid = (from + to) / 2;
    if(x <= mid)
      update(node * 2, from, mid, x, std::min(y, mid), val);
    if(mid + 1 <= y)
      update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, val);
  }
}

std::bitset<1 + nmax> level[1 + sigma];

void explore(int node, int from, int to, int acc, std::bitset<1 + nmax> &sol) {
  level[acc] = level[acc - 1];
  for(int h = 0; h < aint[node].size(); h++)
    level[acc] |= (level[acc]<<(aint[node][h]));

  if(from < to) {
    int mid = (from + to) / 2;
    explore(node * 2, from, mid, acc + 1, sol);
    explore(node * 2 + 1, mid + 1, to, acc + 1, sol);
  } else
    sol |= level[acc];
}

int main() {
  int n, q;
  std::cin >> n >> q;
  for(int i = 1;i <= q; i++) {
    int x, y, val;
    std::cin >> x >> y >> val;
    update(1, 1, n, x, y, val);
  }
  std::bitset<1 + nmax> sol = 0;
  level[0][0] = 1;
  explore(1, 1, n, 1, sol);
  std::vector<int> ans;
  for(int i = 1;i <= n; i++)
    if(sol[i] == 1)
      ans.push_back(i);
  std::cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++)
    std::cout << ans[i] << " ";
  std::cout << '\n';
  return 0;
}