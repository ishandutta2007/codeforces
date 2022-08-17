#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

#define int long long 

struct Change
{
  int t, id, val;
};

#define MAXN 500005

std::vector<int> par(MAXN, -1);
std::vector<int> enemy(MAXN, -1);
std::stack<std::stack<Change> > updates;

int root(int u) {
  while(par[u] >= 0)
    u = par[u];
  return u;
}

int addEdge(int u, int v) {
  u = root(u); v = root(v);

  if(u == v) {
    return 0;
  }

  if(enemy[u] == v) {
    updates.push(std::stack<Change>());
    return 1;
  }

  std::stack<Change> up;
  int eu = enemy[u];
  int ev = enemy[v];
  int ru, rv;
  int ou, ov;

  if(eu == -1 || par[eu] > par[v]) {
    rv = v;
    ov = eu;
  }
  else {
    rv = eu;
    ov = v;
  }

  if(ev == -1 || par[ev] > par[u]) {
    ru = u;
    ou = ev;
  }
  else {
    ru = ev;
    ou = u;
  }

  if(ou != -1) {
    up.push({0, ru, par[ru]});
    par[ru] += par[ou];

    up.push({0, ou, par[ou]});
    par[ou] = ru;
  }

  if(ov != -1) {
    up.push({0, rv, par[rv]});
    par[rv] += par[ov];

    up.push({0, ov, par[ov]});
    par[ov] = rv;
  }

  up.push({1, ru, enemy[ru]});
  enemy[ru] = rv;
  
  up.push({1, rv, enemy[rv]});
  enemy[rv] = ru;

  updates.push(up);

  return 1;
}

void removeLast() {
  std::stack<Change> up = updates.top();
  updates.pop();

  while(!up.empty()) {
    Change c = up.top();
    up.pop();
    if(c.t == 0) {
      par[c.id] = c.val;
    }
    else
      enemy[c.id] = c.val;
  }
}

struct Edge
{
  int u, v;
  int gru, grv;

  inline bool operator<(Edge b) {
    if(grv-gru < b.grv-b.gru)
      return true;
    else if(grv-gru == b.grv-b.gru)
      return (std::pair<int, int>(gru, grv) < std::pair<int, int>(b.gru, b.grv));
    return false;
  }
};

signed main() {
  int n, m, k;
  std::cin >> n >> m >> k;

  int c[n];
  std::vector<Edge> es;
  for(int i = 0; i < n; i++)
    std::cin >> c[i];

  for(int i = 0; i < m; i++) {
    Edge next;
    std::cin >> next.u >> next.v;
    next.u--; next.v--;
    next.gru = c[next.u];
    next.grv = c[next.v];

    if(next.gru > next.grv) {
      next.u ^= next.v ^= next.u ^= next.v;
      next.gru ^= next.grv ^= next.gru ^= next.grv;
    }

    es.push_back(next);
  }

  std::sort(es.begin(), es.end());

  int i;
  std::vector<int> poss(k+1, true);
  int imposs = 0;
  for(i = 0; i < m; i++) {
    if(es[i].gru != es[i].grv)
      break;

    if(!addEdge(es[i].u, es[i].v)) {
      imposs += poss[es[i].gru];
      poss[es[i].gru] = false;
    }
  }

  int max = (k-imposs)*(k-imposs-1);
  max /= 2;

  int lastu = -1, lastv = -1;
  int count = 0;
  int lposs = false;
  while(i < m) {
    //std::cout <<es[i].u << " " << es[i].v << " " <<  es[i].gru << " " << es[i].grv << std::endl;
    if(!poss[es[i].gru] || !poss[es[i].grv]) {
      i++;
      continue;
    }
    
    if(es[i].gru != lastu || es[i].grv != lastv) {
      while(count) {
        removeLast();
        count--;
      }
      lposs = true;
    }

    int cur = addEdge(es[i].u, es[i].v);
    if(!cur) {
      int curu = es[i].gru, curv= es[i].grv;
      while(i < m && es[i+1].gru == curu && es[i+1].grv == curv) {
        i++;
      }
      max--;
    }
    else {
      count++;
    }

    lastu = es[i].gru, lastv = es[i].grv;
    i++;
  }

  std::cout << max << std::endl;

  return 0;
}