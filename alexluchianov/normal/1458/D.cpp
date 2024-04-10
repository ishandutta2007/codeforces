#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 500000;
int v[5 + nmax];
int edges[5 + nmax * 2];

void build_string(int node, std::string &result) {
  if(1 < edges[node - 1]){
    std::cout << 0;
    edges[node - 1]--;
    build_string(node - 1, result);
  } else if(1 < edges[node]) {
    std::cout << 1;
    edges[node]--;
    build_string(node + 1, result);
  } else if(1 == edges[node - 1]) {
    std::cout << 0;
    edges[node - 1]--;
    build_string(node - 1, result);
  } else if(1 == edges[node]) {
    std::cout << 1;
    edges[node]--;
    build_string(node + 1, result);

  }
}

std::string solve() {
  std::string s;
  std::cin >> s;
  int n = s.size();

  for(int i = 1; i <= n; i++)
    v[i] = v[i - 1] + (s[i - 1] -'0') * 2 - 1;
  int start = nmax;

  for(int i = 1; i <= n; i++)
    edges[start + std::min(v[i], v[i - 1])]++;

  std::string result;
  build_string(start, result);
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    std::cout << solve() << '\n';
  }
  return 0;
}