#include <iostream>
#include <algorithm>
#include <set>

#define int long long

const int MAXA = 10000007;
const int MAXN = 1000006;
const int INF = 1000000000;

std::set<std::pair<int, int> > unreach;
std::set<std::pair<int, int> > avail;
int focus[MAXN], val[MAXN], dis[MAXN];
int n, q, s, d;

void addFocus(int x) {
  //std::cout << x << std::endl;
  auto it = unreach.lower_bound({x, -1});
  int dist = (*it).first-x;
  int id = (*it).second;

  if(id != -1 && dist < dis[id]) {
    avail.erase({dis[id], id});
    dis[id] = dist;
    focus[id] = x;
    avail.insert({dis[id], id});
  }

  it--;
  dist = x-(*it).first;
  id = (*it).second;

  if(id != -1 && dist < dis[id]) {
    avail.erase({dis[id], id});
    dis[id] = dist;
    focus[id] = x;
    avail.insert({dis[id], id});
  }
}

void removeNext() {
  int id2 = (*avail.begin()).second;
  avail.erase(avail.begin());
  unreach.erase({val[id2], id2});

  int x = focus[id2];

  addFocus(val[id2] + d);
  addFocus(val[id2] - d);
  addFocus(x);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n >> q >> s >> d;
  s--;

  unreach.insert({-MAXA, -1});
  unreach.insert({MAXA, -1});

  for(int i = 0; i < n; i++) {
    std::cin >> val[i];
    if(i != s) {
      unreach.insert({val[i], i});
      dis[i] = INF;
    }
  }

  int qans[q];
  std::pair<int, std::pair<int, int> > qhelp[q];

  for(int i = 0; i < q; i++) {
    std::cin >> qhelp[i].second.first >> qhelp[i].first;
    qhelp[i].second.second = i;
  }

  std::sort(qhelp, qhelp+q);

  addFocus(val[s]+d);
  addFocus(val[s]-d);

  for(int i = 0; i < q; i++) {
    while((!avail.empty()) && (*avail.begin()).first <= qhelp[i].first)
      removeNext();

    int id = qhelp[i].second.first-1;
    int cur = !unreach.count({val[id], id});
    qans[qhelp[i].second.second] = cur;
  }

  for(int i = 0; i < q; i++)
    std::cout << (qans[i] ? "Yes" : "No") << std::endl;

  return 0;
}