#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const modulo =   998244353;
int const modulo2 = 1000000007;

int lgpow(int a, ll b, int modu) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2, modu);
    if(b % 2 == 0)
      return 1LL * result * result % modu;
    else
      return 1LL * result * result % modu * a % modu;
  }
}
int const nmax = 200000;

int v[1 + nmax][2];

std::pair<int,int> _add(std::pair<int,int> f1, std::pair<int,int> f2) {
  return {(f1.first + f2.first) % modulo, (f1.second + f2.second) % modulo2};
}

std::pair<int,int> _multiply(std::pair<int,int> f1, std::pair<int,int> f2) {
  return {1LL * f1.first * f2.first % modulo, 1LL * f1.second * f2.second % modulo2};
}

std::vector<int> changes[1 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  std::pair<int, int> result(0,0);
  for(int i = 1;i <= m; i++) { 
    std::cin >> v[i][0] >> v[i][1];
    if(v[i][1] < v[i][0])
      std::swap(v[i][0], v[i][1]);
    ll id = 1LL * v[i][0] * n + v[i][1];
   
    result = _add(result, {lgpow(2, id, modulo), lgpow(2, id, modulo2)});
    changes[v[i][0]].push_back(i);
    changes[v[i][1]].push_back(i);
  }
  std::pair<int,int> curr = result;
  
  std::map<std::pair<int,int>, int> mp;

  mp[result] = 1;

  for(int i = 1;i < n; i++) {
    curr = _multiply(curr, {lgpow(2, n + 1, modulo), lgpow(2, n + 1, modulo2)});
    for(int j = 0; j < changes[n - i + 1].size(); j++) {
      int id = changes[n - i + 1][j];
      int x = (v[id][0] + i - 1) % n + 1;
      int y = (v[id][1] + i - 1) % n + 1;
      if(y < x)
        std::swap(x, y);
      ll id1 = n + y;
      ll id2 = 1LL * n * y + (n + 1) ;
      
      curr = _add(curr, {modulo - lgpow(2, id2, modulo), modulo2 - lgpow(2, id2, modulo2)});
      curr = _add(curr, {lgpow(2, id1, modulo), lgpow(2, id1, modulo2)});
      
      if(mp[curr] == 1) {
        std::cout << "Yes\n";
        return 0;
      }
      mp[curr] = 1;     
    }
  }
  std::cout << "No\n";
  return 0;
}