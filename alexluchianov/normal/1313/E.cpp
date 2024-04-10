#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 500000;

std::vector<int> zAlgo(std::string s) {
  int center = 0;
  std::vector<int> pre(s.size());
  
  for(int i = 1; i < s.size(); i++) {
    if(i < center + pre[center]) 
      pre[i] = std::min(center + pre[center] - 1 - i, pre[i - center]);
    while(i + pre[i] < s.size() && s[i + pre[i]] == s[pre[i]])
      pre[i]++;
    if(center + pre[center] < i + pre[i])
      center = i;
  }
  
  /*
  std::cout << "Zalgo\n";
  std::cout << s << '\n';
  for(int i = 0; i < pre.size(); i++)
    std::cout << pre[i] << " ";
  std::cout << '\n';
  */

  return pre;
}

std::vector<int> zWrapper(std::string s, std::string pattern) {
  std::vector<int> answer(s.size());
  std::vector<int> aux = zAlgo(pattern + "#" + s);

  for(int i = 0; i < s.size(); i++)
    answer[i] = aux[i + pattern.size() + 1];
  return answer;
}

class SegmentTree{
private:
  std::vector<ll> aint;
  std::vector<ll> lazy;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }

  void cleannode(int node, int from, int to) {
    if(lazy[node] == 0)
      return ;
    if(from < to) {
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] += 1LL * (to - from + 1) * lazy[node];
    lazy[node] = 0;
  }
  
  void update(int node, int from, int to, int x, int y, int val) {

    cleannode(node, from, to);
    if(from == x && to == y) {
      lazy[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);

      if(x <= mid)
        update(node * 2, from, mid, x, std::min(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, val);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }
  }

  ll query(int node, int from, int to, int x, int y) {
    cleannode(node, from, to);

    if(from == x && to == y) {
      cleannode(node, from, to);
      return aint[node];
    } else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return query(node * 2, from, mid, x, mid) +
               query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  std::string a, b, s;
  std::cin >> a >> b >> s;
  std::vector<int> f = zWrapper(a, s);
  std::reverse(b.begin(), b.end());
  std::reverse(s.begin(), s.end());

  std::vector<int> g = zWrapper(b, s);
  std::reverse(g.begin(), g.end());
  
  int lim = 1 + m;
  SegmentTree aint(lim);

  ll result = 0;
  int ptr = 0;
  
  for(int i = 0; i < n; i++)
    f[i] = std::min(f[i], m - 1);
  for(int i = 0; i < n; i++)
    g[i] = std::min(g[i], m - 1);

  for(int i = 0; i < n; i++) {
    while(ptr < n && ptr < i + m - 1)
      aint.update(1, 0, m, 0 ,g[ptr++], 1);
    if(0 < i)
      aint.update(1, 0, m, 0, g[i - 1], -1);
    if(0 < f[i])
      result += aint.query(1, 0, m, m - f[i], m - 1);
  }

  std::cout << result << '\n';
  return 0;
}