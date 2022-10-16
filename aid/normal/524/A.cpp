#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int kN = 1000;

map<int, int> mp;
int ind = 0;
vector<int> rev(kN); 

int Get(int x) {
  if (mp.find(x) == mp.end()) {
    mp[x] = ind++;
    rev[ind - 1] = x;
  }
  return mp[x];
}

bool m[kN][kN];
int c[kN];

vector<int> g[kN];

int main() {
  std::ios_base::sync_with_stdio(false);
  int q, k;
  cin >> q >> k;
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    m[Get(a)][Get(b)] = 1;
    m[Get(b)][Get(a)] = 1;
  }
  for (int i = 0; i < ind; ++i) {
    for (int j = 0; j < ind; ++j)
      c[i] += m[i][j];
  }
  for (int i = 0; i < ind; ++i) {
    for (int j = 0; j < ind; ++j) {
      if (m[i][j] || i == j) {
        continue;
      }
      int cnt = 0;
      for (int k = 0; k < ind; ++k) {
        if (k != i && k !=j && m[k][j] && m[k][i]) {
          ++cnt;
        }
      }
      if (c[i] * k <= cnt * 100) {
        g[i].push_back(j);  
      }
    }
  }
  for (auto w : mp) {
    int i = Get(w.first);
    int id = w.first;
    cout << id << ": " << g[i].size() << " ";
    for (int j = 0; j < g[i].size(); ++j) {
      g[i][j] = rev[g[i][j]];
    }
    sort(g[i].begin(), g[i].end());
    for (auto x : g[i]) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}