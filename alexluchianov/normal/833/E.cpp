#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

struct Event{
  int time;
  int val;
  bool operator < (Event const oth) {
    return time < oth.time;
  }
};

int const nmax = 300000;
int const threshold = 300;
int cost[1 + nmax];
int special[1 + nmax], frec[1 + nmax];

int base[1 + nmax], best[1 + nmax];
std::vector<std::pair<int,int>> g[1 + nmax], gwhite[1 + nmax];

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
        aint[node] += val;
    }
    int query(int node, int from, int to, int x, int y) {
      if(y < x)
        return 0;
      if(from == x && to == y) {
        return aint[node];
      } else {
        int mid = (from + to) / 2;
        if(x <= mid && y <= mid)
          return query(node * 2, from, mid, x, y);
        else if(mid + 1 <= x && mid + 1 <= y)
          return query(node * 2 + 1, mid + 1, to, x, y);
        else
          return std::max(query(node * 2, from, mid, x, mid), query(node * 2 + 1, mid + 1, to, mid + 1, y));
      }
    }
};
int pos[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, target;
  std::cin >> n >> target;
  std::vector<Event> events;
  std::vector<std::pair<int,int>> clouds;

  for(int i = 1;i <= n; i++) {
    int l, r, c;
    std::cin >> l >> r >> c;
    cost[i] = c;
    events.push_back({l, i});
    events.push_back({r, -i});
    clouds.push_back({c, i});
  }

  std::sort(clouds.begin(), clouds.end());
  for(int i = 0; i < clouds.size(); i++)
    pos[clouds[i].second] = 1 + i;
  SegmentTree aint(n);

  std::set<int> myset;
  std::sort(events.begin(), events.end());
  std::vector<std::pair<int,int>> edges;


  for(int i = 0; i < events.size(); i++) {
    Event curr = events[i];
    if(curr.val < 0)
      myset.erase(-curr.val);
    else
      myset.insert(curr.val);
    if(myset.size() == 2) {
      std::set<int>::iterator it = myset.begin();
      int x = *it;
      it++;
      int y = *it;
      edges.push_back({x, y});
    }
  }

  myset.clear();

  std::sort(edges.begin(), edges.end());
  edges.erase(std::unique(edges.begin(), edges.end()), edges.end());

  for(int i = 0; i < edges.size(); i++) {
    frec[edges[i].first]++;
    frec[edges[i].second]++;
  }

  for(int i = 1;i <= n; i++)
    if(threshold <= frec[i])
      special[i] = 1;

  for(int i = 0; i < edges.size(); i++) {
    int x = edges[i].first;
    int y = edges[i].second;
    if(cost[x] + cost[y] <= target) {
      g[x].push_back({y, 0});
      g[y].push_back({x, 0});
      if(special[y] == 1)
        gwhite[x].push_back({y, 0});
      if(special[x] == 1)
        gwhite[y].push_back({x, 0});
    }
  }

  int last = 0, result = 0, gol = 0;

  std::vector<std::pair<int,int>> samples;
  samples.push_back({0, 0});

  for(int i = 0; i < events.size(); i++) {
    if(myset.size() == 2) {
      std::set<int>::iterator it = myset.begin();
      int x = *it;
      it++;
      int y = *it;
      if(cost[x] + cost[y] <= target) {
        int dim = events[i].time - last;
        if(special[x] == 0) {
          for(int h = 0; h < g[x].size(); h++) {
            int to = g[x][h].first;
            if(to == y) {
              g[x][h].second += dim;
              result = std::max(result, base[to] + base[x] + g[x][h].second);
            }
          }
        } else {
          for(int h = 0; h < gwhite[x].size(); h++) {
            int to = gwhite[x][h].first;
            if(to == y) {
              gwhite[x][h].second += dim; 
              best[to] = std::max(best[to], base[x] + gwhite[x][h].second);
              result = std::max(result, best[to] + base[to]);
            }
          }
        }

        if(special[y] == 0) {
          for(int h = 0; h < g[y].size(); h++) {
            int to = g[y][h].first;
            if(to == x) {
              g[y][h].second += dim;
              result = std::max(result, base[to] + base[y] + g[y][h].second);
            }
          }
        } else {
          for(int h = 0; h < gwhite[y].size(); h++) {
            int to = gwhite[y][h].first;
            if(to == x) {
              gwhite[y][h].second += dim; 
              best[to] = std::max(best[to], base[y] + gwhite[y][h].second);
              result = std::max(result, best[to] + base[to]);
            }
          }
        }
      }
    } else if(myset.size() == 1) {
      int node = *myset.begin();
      if(cost[node] <= target) {
        int dim = events[i].time - last;
        base[node] += dim;

        aint.update(1, 1, n, pos[node], dim);

        int pref = 0;
        for(int jump = (1 << 20); 0 < jump; jump /= 2)
          if(pref + jump <= n && clouds[pref + jump - 1].first <= target - cost[node])
            pref += jump;
        result = std::max(result, base[node]);

        if(0 < pref) {
          if(pref < pos[node])
            result = std::max(result, base[node] + aint.query(1, 1, n, 1, pref));
          else 
            result = std::max(result, base[node] + std::max(aint.query(1, 1, n, 1, pos[node]- 1), aint.query(1, 1, n, pos[node] + 1, pref)));
        }

        if(special[node] == 0) {
          for(int h = 0; h < g[node].size(); h++) {
            int to = g[node][h].first;
            result = std::max(result, base[to] + base[node] + g[node][h].second);
          }
        } else
          result = std::max(result, best[node] + base[node]); 

        for(int h = 0; h < gwhite[node].size(); h++) {
          int to = gwhite[node][h].first;
          gwhite[node][h].second += dim; 
          best[to] = std::max(best[to], base[node] + gwhite[node][h].second);
        }
      }
    } else if(myset.size() == 0) {
      gol += events[i].time - last;
    }

    samples.push_back({events[i].time, result + gol});
    
    Event curr = events[i];
    if(curr.val < 0)
      myset.erase(-curr.val);
    else
      myset.insert(curr.val);
    last = events[i].time;
  }

  int q;
  std::cin >> q;
  for(int i = 1;i <= q; i++) {
    int ptr = 0;
    int tar;
    std::cin >> tar;
    for(int jump = (1 << 20); 0 < jump; jump /= 2)
      if(ptr + jump < samples.size() && samples[ptr + jump].second < tar)
        ptr += jump;
    if(ptr + 1 == samples.size())
      std::cout << tar - samples[ptr].second + samples[ptr].first << '\n';
    else {
      ptr++;
      std::cout << samples[ptr].first - (samples[ptr].second - tar) << '\n';
    }
  }
  return 0;
}