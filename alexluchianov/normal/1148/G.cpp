#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int const valmax = 10000000;
int const imp_size = 14;
int const fast_size = 300;

std::bitset<1 + valmax> ciur;
int v[5 + nmax];
std::vector<int> decomp[5 + nmax];
std::vector<std::vector<int>> prime_app;
std::vector<int> is_imp;
std::vector<int> primes;

void computeciur() {
  for(int i = 2; i <= valmax; i++)
    if(ciur[i] == 0)
      for(int j = i * 2; j < valmax; j += i)
        ciur[j] = 1;
  for(int i = 2; i <= valmax; i++)
    if(ciur[i] == 0)
      primes.push_back(i);
  prime_app.resize(primes.size());
  is_imp.resize(primes.size());
  //std::cerr << "Found " << primes.size() << " " << "primes" << '\n';
}

std::vector<int> decompose(int number) {
  std::vector<int> decomp;
  for(int i = 0; i < primes.size() && primes[i] * primes[i] <= number; i++) {
    if(number % primes[i] == 0) {
      decomp.push_back(i);
      while((number % primes[i]) == 0) {
        number /= primes[i];
      }
    }
  }

  if(1 < number) 
    decomp.push_back(std::lower_bound(primes.begin(), primes.end(), number) - primes.begin());
  return decomp;
}
std::bitset<1 + nmax> afast[1 + fast_size];


std::vector<int> compute_imp(int n) {
  std::vector<std::pair<int,int>> sol(primes.size());
  for(int j = 0; j < sol.size(); j++)
    sol[j] = {prime_app[j].size(), j};

  std::sort(sol.begin(), sol.end());
  std::reverse(sol.begin(), sol.end());
  std::vector<int> imp;
  
  for(int i = 0; i < fast_size; i++)
    imp.push_back(sol[i].second);
  for(int i = 0; i < fast_size; i++) {
    int number = imp[i];
    afast[i].set();
    for(int j = 0; j < prime_app[number].size(); j++)
      afast[i][prime_app[number][j]] = 0;
  }
  return imp;
}


std::vector<int> queries[1 << imp_size];
std::bitset<1 + nmax> active;

std::vector<int> g[5 + nmax];
std::bitset<1 + nmax> prev[1 + imp_size];

void add_edge(int x, int y) {
  g[x].push_back(y);
  g[y].push_back(x);
}

void backt(int pos, int mask, std::vector<int> &imp, int n) {
  if(pos == imp_size) {
    for(int i = 0; i < queries[mask].size(); i++) {
      int number = queries[mask][i];
      prev[pos] = active;
      
      for(int j = 0; j < decomp[number].size(); j++) {
        int prime = decomp[number][j];
        if(imp_size < is_imp[prime]) {
          active &= afast[is_imp[prime] - 1];
        }
      }
      
      for(int j = 0; j < decomp[number].size(); j++) {
        int prime = decomp[number][j];
        if(is_imp[prime] == 0) {
          for(int j = 0; j < prime_app[prime].size(); j++) {
            int number = prime_app[prime][j];
            if(active[number] == 1) {
              active[number] = 0;
            }
          }
        }
      }
      int counter = 2;

      for(int j = active._Find_first(); j <= n && 0 < counter; j = active._Find_next(j)) {
        int target = j;
        if(active[target] == 1) {
          counter--;
          add_edge(target, number);
        }
      }
      active = prev[pos];
    }
  } else {
    backt(pos + 1, mask, imp, n);
    prev[pos] = active;
    active &= afast[pos];
    backt(pos + 1, mask | (1 << pos), imp, n);
    active = prev[pos];
  }
}
int seen[5 + nmax];

void dfs(int node, std::vector<int> &sol) {
  sol.push_back(node);
  seen[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(seen[to] == 0) {
      dfs(to, sol);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  computeciur();

  int n, k;
  std::cin >> n >> k;
  n = 2 * k;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    decomp[i] = decompose(v[i]);
    for(int j = 0; j < decomp[i].size(); j++)
      prime_app[decomp[i][j]].push_back(i);
  }

  std::vector<int> imp = compute_imp(n);
  for(int i = 0; i < imp.size(); i++)
    is_imp[imp[i]] = 1 + i;
  
  for(int i = 1;i <= n; i++) {
    int mask = 0;
    for(int j = 0; j < decomp[i].size(); j++)
      for(int h = 0; h < imp_size; h++)
        if(decomp[i][j] == imp[h])
          mask |= (1 << h);
    queries[mask].push_back(i);
  }
  

  active.set();
  active[0] = 0;

  backt(0, 0, imp, n);
  std::vector<std::vector<int>> sol;
  for(int i = 1;i <= n; i++) {
    if(seen[i] == 0) {
      std::vector<int> aux;
      dfs(i, aux);
      sol.push_back(aux);
    }
  }
  bool bigger = false;
  int onecount = 0;
  for(int i = 0; i < sol.size(); i++) {
    bigger |= (3 <= sol[i].size());
    onecount += (1 == sol[i].size());
  }
  std::vector<int> answer;
  
  if(k <= onecount) {
    for(int i = 0; i < sol.size(); i++) 
      if(sol[i].size() == 1 && answer.size() < k)
        answer.push_back(sol[i][0]);
  } else if(bigger == false) {
    for(int i = 0; i < sol.size() && i < k; i++)
      answer.push_back(sol[i][0]);
  } else {
    for(int i = 0; i < sol.size(); i++) {
      if(2 <= sol[i].size() && answer.size() + 2 <= k) {
        answer.push_back(sol[i][0]);
        answer.push_back(sol[i][1]);
      }
    }
    for(int i = 0; i < sol.size(); i++) {
      if(2 < sol[i].size()) {
        for(int j = 2; j < sol[i].size() && answer.size() + 1 <= k; j++) {
          answer.push_back(sol[i][j]);
        }
      }
    }
  }

  for(int i = 0; i < answer.size(); i++)
    std::cout << answer[i] << " ";
  std::cout << '\n';
  return 0;
}