#include <cmath>
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

struct pt
{
  ll x, y;
};

bool operator < (const pt &a, const pt &b)
{
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw (pt a, pt b, pt c) {
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}


int main() {
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pt> e;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    y -= x * x;
    e.push_back({x, y});
  }
  sort(e.begin(), e.end());
  pt a = e[0], b = e.back();
  vector <pt> t = {a};
  for (int i = 1; i < (int) e.size(); i++)
  {
    if (i == (int) e.size() - 1 || cw(a, e[i], b))
    {
      while (t.size() >= 2 && !cw(t[(int) t.size() - 2], t.back(), e[i]))
      {
        t.pop_back();
      }
      t.push_back(e[i]);
    }
  }
  int ans = 0;
  for (int i = 1; i < (int) t.size(); i++)
  {
    if (t[i].x != t[i - 1].x)
    {
      ans++;
    }
  }
  cout << ans << '\n';
}