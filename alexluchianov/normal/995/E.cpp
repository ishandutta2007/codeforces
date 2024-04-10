#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <map>

using ll = long long;
int const threshold = 100000;
int const lim = 200;
int modulo;

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b/ 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

void explore(int start, std::map<int,std::pair<int,int>> &dp) {
  dp[start] = {0, start};
  std::queue<std::pair<int,int>> q;
  q.push({0, start});
  int steps = 0;
  while(0 < q.size() && steps < threshold) {
    steps++;
    int node = q.front().second;
    int cost = q.front().first;
    q.pop();
    int to = (node + 1) % modulo;
    if(dp.find(to) == dp.end()) {
      dp[to] = {cost + 1, node};
      q.push({cost + 1, to});
    }
    to = (node + modulo - 1) % modulo;
    if(dp.find(to) == dp.end()) {
      dp[to] = {cost + 1, node};
      q.push({cost + 1, to});
    }
    to = lgpow(node, modulo - 2);
    if(dp.find(to) == dp.end()) {
      dp[to] = {cost + 1, node};
      q.push({cost + 1, to});
    }
  }
}

struct Event{
  int op;
  int pos;
  int acc;
  bool operator < (Event const oth) {
    return pos < oth.pos;
  }
};

int getmove(int node, int to) {
  if((node + 1) % modulo == to)
    return 1;
  else if((node + modulo - 1) % modulo == to)
    return 2;
  assert(lgpow(node, modulo - 2) == to);
  return 3;
}

void print(int node, int rev, std::map<int, std::pair<int,int>> &dp) {
  std::pair<int,int> sol = dp[node];
  if(0 < sol.first) {
    if(rev == 2)
      std::cout << getmove(node, sol.second) << " ";
    print(sol.second, std::max(1, rev), dp);
    if(rev == 1)
      std::cout << getmove(sol.second, node) << " ";
  }
}

int main() {
  int start, stop;
  std::cin >> start >> stop >> modulo;
  std::map<int,std::pair<int,int>> dp1, dp2;
  explore(start, dp1);
  explore(stop, dp2);
  std::vector<Event> aux;
  for(std::map<int,std::pair<int,int>>::iterator it = dp1.begin(); it != dp1.end(); it++)
    aux.push_back({1, it->first, it->second.first});
  for(std::map<int,std::pair<int,int>>::iterator it = dp2.begin(); it != dp2.end(); it++)
    aux.push_back({2, it->first, it->second.first});
  std::sort(aux.begin(), aux.end());
  
  for(int i = 1;i < aux.size(); i++) {
    if(aux[i - 1].op != aux[i].op && (aux[i].pos - aux[i - 1].pos) + aux[i - 1].acc + aux[i].acc <= lim) {
      std::cout << aux[i].pos - aux[i - 1].pos + aux[i - 1].acc + aux[i].acc  << '\n';
      
      if(aux[i - 1].op == 1) {
        print(aux[i - 1].pos, 1, dp1);
        for(int j = aux[i - 1].pos; j < aux[i].pos; j++)
          std::cout << 1 << " " ;
        print(aux[i].pos, 2, dp2);
      } else {
        print(aux[i].pos, 1, dp1);
        for(int j = aux[i - 1].pos; j < aux[i].pos; j++)
          std::cout << 2 << " " ;
        print(aux[i - 1].pos, 2, dp2);
      }
      std::cout << '\n';
      return 0;
    }
  }
  assert(1 == 2);
  return 0;
}