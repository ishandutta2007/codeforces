#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <map>
#include <vector>

using ll = long long;

class SegmentTree{
private:
  std::vector<int> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }

  void update(int node, int from, int to, int x, int val) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = std::max(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = val;
  }
  int query(int node, int from, int to, int x, int y) {
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

int const nmax = 500000;
int v[1 + nmax], dp[1 + nmax];
int nxt[1 + nmax], rev[1 + nmax];
std::map<int,int> mp;

void normalize(int n) {
  int ptr = 0;
  for(int i = 1;i <= n; i++) {
    if(mp[v[i]] == 0)  {
      mp[v[i]] = ++ptr;
      rev[ptr] = v[i];
    }
    v[i] = mp[v[i]];
  }
}
std::vector<int> frec[1 + nmax];
int pos[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  normalize(n);
  SegmentTree aint(n);
  for(int i = 1;i <= n; i++) {
    frec[v[i]].push_back(i);
    pos[i] = frec[v[i]].size() - 1;
  }

  for(int i = 1;i <= n; i++) {
    if(pos[i] + 1 < frec[v[i]].size()) {
      int target = frec[v[i]][pos[i] + 1];
      if(i + 1 <= target - 1)
        nxt[target] = aint.query(1, 1, n, i + 1, target - 1);
      aint.update(1, 1, n, target, i);
    }
  }

  for(int i = 1;i <= n; i++) {
    dp[i] = dp[i - 1];
    if(0 < nxt[i]) 
      dp[i] = std::max(dp[i], dp[nxt[i] - 1] + 1);
    if(3 <= pos[i]) 
      dp[i] = std::max(dp[i], dp[frec[v[i]][pos[i] - 3] - 1] + 1);
  }

  std::vector<int> sol;
  while(0 < n) {
    if(dp[n] == dp[n - 1]) 
      n--;
    else {
      if(0 < nxt[n] && dp[nxt[n] - 1] + 1 == dp[n]) {
        sol.push_back(v[n]);
        sol.push_back(v[nxt[n]]);
        sol.push_back(v[n]);
        sol.push_back(v[nxt[n]]);
        n = nxt[n] - 1;
      } else {
        sol.push_back(v[n]);
        sol.push_back(v[n]);
        sol.push_back(v[n]);
        sol.push_back(v[n]);
        n = frec[v[n]][pos[n] - 3] - 1;
      }
    }
  }
  std::reverse(sol.begin(), sol.end());
  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << rev[sol[i]] << " ";
  std::cout << '\n';
  return 0;
}