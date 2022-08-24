#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 1000;

vector <int>g[N];
bool u[N];

int best = -1,go = -1;

vector <int> arr;
vector <int> ans;

void dfs(int v, int pr = -1, int d = 0) {
  u[v] = true;
  arr.push_back(v);
  if (d > best) {
    best= d;
    go = v;
    ans = arr;
  }
  for(int to : g[v]) {
    if(to != pr) {
      dfs(to,v, d + 1);
    }
  }
  arr.pop_back();
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector <pair <int,int> > ok;
  for (int i= 0; i < n; i++) {
    if (!u[i]) {
      best = -1, go = -1;
      dfs(i);
      int s = go;
      best = -1, go = -1;
      dfs(s);
      int c = ans[(int) ans.size() / 2];
      ok.push_back({ans.size(),c});
    }
  }
  sort(ok.rbegin(), ok.rend());
  vector <pair <int, int> > ed;
  for(int i= 1; i < (int) ok.size(); i++) {
    ed.push_back({ok[0].second, ok[i].second});
    g[ok[0].second].push_back(ok[i].second);
    g[ok[i].second].push_back(ok[0].second);
  }
  best = -1, go = -1;
  dfs(0);
  int s = go;
  best = -1, go = -1;
  dfs(s);
  cout <<best <<'\n';
  for(auto c : ed) {
    cout << c.first + 1 << ' ' << c.second + 1 << '\n';
  }
}