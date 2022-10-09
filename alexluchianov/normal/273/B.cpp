#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int const nmax = 100000;
int modulo = 2;
using ll = long long;

class ModuloRing{
private:
  void gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
      x = 1;
      y = 0;
    } else {
      gcd(b, a % b, x, y);
      int aux = x;
      x = y;
      y = aux - a / b * y;
    }
  }
public:
  int number;
  ModuloRing(ll number_ = 0) {
    number = number_ % modulo;
  }
  ModuloRing operator + (ModuloRing a) {
    return (number + a.number);
  }
  ModuloRing operator - (ModuloRing a) {
    return (modulo + number - a.number);
  }
  ModuloRing operator * (ModuloRing a) {
    return 1LL * number * a.number;
  }
  ModuloRing operator / (ModuloRing a) {
    int x, y;
    gcd(a.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x;
  }

  friend std::ostream& operator << (std::ostream& output, ModuloRing &a) {
    output << a.number;
    return output;
  }
};

std::vector<int> v[1 + 2 * nmax];

ModuloRing fact(int number, int exp) {
  ModuloRing result(1);
  for(int i = 1;i <= number; i++) {
    int a = i;
    while(0 < exp && a % 2 == 0) {
      a /= 2;
      exp--;
    }
    result = result * a;
  }
  return result;
}
int a[1 + nmax], b[1 + nmax];

void normalize(int n) {
  std::vector<int> temp;
  for(int i = 1;i <= n; i++) {
    temp.push_back(a[i]);
    temp.push_back(b[i]);
  }
  std::sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  std::map<int,int> mp;
  for(int i = 0; i < temp.size(); i++)
    mp[temp[i]] = 1 + i;
  for(int i = 1;i <= n; i++) {
    a[i] = mp[a[i]];
    b[i] = mp[b[i]];
  }
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int n, val;
  std::cin >> n;
  for(int i = 1;i <= n; i++) 
    std::cin >> a[i];
  for(int i = 1; i <= n; i++) 
    std::cin >> b[i];
  normalize(n);
  for(int i = 1;i <= n; i++) {
    v[a[i]].push_back(i);
    v[b[i]].push_back(i);
  }
  
  std::cin >> modulo;
  ModuloRing result(1);
  
  for(int i = 1;i <= 2 * n; i++) {
    std::sort(v[i].begin(), v[i].end());
    int exp = 0;
    for(int j = 1;j < v[i].size(); j++)
      if(v[i][j - 1] == v[i][j])
        exp++;
    result = result * fact(v[i].size(), exp);
  }
  std::cout << result << '\n';
}