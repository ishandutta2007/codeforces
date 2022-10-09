#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 100000;
ll v[1 + nmax];
int id[1 + nmax];

class SegmentTree{
private:
  std::vector<std::pair<int,int>> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, std::pair<int,int> val) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = std::max(aint[node * 2],aint[node * 2 + 1]);
    } else
      aint[node] = val;
  }

  std::pair<int,int> query(int node, int from, int to, int x, int y) {
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return std::max(query(node * 2, from, mid, x, mid),
               query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};
int dp[1 + nmax], last[1 + nmax];

void print(int node) {
  if(1 < dp[node])
    print(last[node]);
  std::cout << node << " ";
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, d;
  std::cin >> n >> d;
  std::vector<std::pair<ll,int>> aux;
  
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    aux.push_back({v[i], i});
  }
  aux.push_back({0, 0});
  std::sort(aux.begin(), aux.end());
  for(int i = 0; i < aux.size(); i++)
    id[aux[i].second] = i;
  SegmentTree aint(2 + n);
  int result = 0;

  for(int i = 1;i <= n; i++) {
    int pos = id[i];
    int x = 0, x2 = 0;
    for(int jump = (1 << 20); 0 < jump; jump /= 2) {
      if(x + jump <= n && aux[x + jump].first <= v[i] - d)
        x += jump;
      if(x2 + jump <= n && aux[x2 + jump].first < v[i] + d)
        x2 += jump;
    }

    std::pair<int,int> sol = std::max(aint.query(1, 0, n + 1, 0, x),
                                      aint.query(1, 0, n + 1, x2 + 1, n + 1));
    last[i] = sol.second;
    dp[i] = sol.first + 1;
    aint.update(1, 0, n + 1, pos, {dp[i], i});
    if(dp[result] < dp[i])
      result = i;
  }

  std::cout << dp[result] << '\n';
  print(result);
  std::cout << '\n';
  return 0;
}