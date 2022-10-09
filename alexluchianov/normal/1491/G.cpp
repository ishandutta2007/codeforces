#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax], side[1 + nmax];
std::vector<std::pair<int,int>> sol;
int seen[1 + nmax];

int getsz(int node) {
  int acc = 0;
  while(seen[node] == 0) {
    seen[node] = 1;
    acc++;
    node = v[node];
  }
  return acc;
}

void makemove(int x, int y) {
  sol.push_back({x, y});
  std::swap(v[x], v[y]);
  side[v[x]] = !side[v[x]];
  side[v[y]] = !side[v[y]];
}


void solvemarked(int start) {
  int node = start;
  std::vector<int> pos;
  while(seen[node] == 1) {
    pos.push_back(node);
    seen[node] = 2;
    node = v[node];
  }
  int sec = 0;
  for(int i = 0; i < pos.size(); i++)
    if(side[v[pos[i]]] == 1)
      sec = i;
  for(int i = 1; i < sec; i++) 
    makemove(pos[0], pos[i]);
  for(int i = sec + 1; i < pos.size(); i++)
    makemove(pos[sec], pos[i]);
  makemove(pos[0], pos[sec]);
}

void solvealone(int start) {
  int node = start;
  std::vector<int> pos;
  while(seen[node] == 1) {
    pos.push_back(node);
    seen[node] = 2;
    node = v[node];
  }

  if(pos.size() == 2) {
    int exterp = 1;
    while(exterp == pos[0] || exterp == pos[1])
      exterp++;
    makemove(pos[1], exterp);
    makemove(pos[0], exterp);
    makemove(pos[1], exterp);
  } else {
    for(int i = 1; i < pos.size() - 1; i++)
      makemove(pos[0], pos[i]);

    makemove(pos[1], pos.back());
    makemove(pos[0], pos[pos.size() - 1]);
    makemove(pos[0], pos[1]);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  std::vector<std::pair<int,int>> aux;
  
  for(int i = 1;i <= n; i++) 
    if(seen[i] == 0) {
      int val = getsz(i);
      if(1 < val)
        aux.push_back({val, i});
    }

  std::sort(aux.begin(), aux.end());
  for(int i = 1; i < aux.size(); i += 2) {
    makemove(aux[i - 1].second, aux[i].second);
    solvemarked(aux[i].second);
  }
  
  if(aux.size() % 2 == 1)
    solvealone(aux.back().second);
  
  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i].first << " " << sol[i].second << '\n';
  return 0;
}