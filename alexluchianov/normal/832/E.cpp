#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const modulo = 5;

class ModuloRing{
private:
  void gcd(int a, int b, int &x, int &y){
    if(b == 0){
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
  ModuloRing(int number_ = 0){
    number = number_ % modulo;
  }
  ModuloRing operator + (ModuloRing const &a) const {
    return (number + a.number);
  }
  ModuloRing operator - (ModuloRing const &a) const {
    return (modulo + number - a.number);
  }
  ModuloRing operator * (ModuloRing const &a) const {
    return number * a.number;
  }
  ModuloRing operator / (ModuloRing const &a){
    int x, y;
    gcd(a.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return number * x;
  }
};

class Zvector{
public:
  vector<ModuloRing> v;

  Zvector(int n = 0){
    v.resize(n);
  }
  Zvector(string s){
    v.resize(s.size());
    for(int i = 0; i < s.size(); i++)
      v[i] = s[i] - 'a';
  }
  Zvector operator + (Zvector const &a) const {
    assert(v.size() == a.v.size());
    Zvector result(v.size());
    for(int i = 0; i < v.size(); i++)
      result.v[i] = v[i] + a.v[i];
    return result;
  }
  Zvector operator - (Zvector const &a) const {
    assert(v.size() == a.v.size());
    Zvector result(v.size());
    for(int i = 0; i < v.size(); i++)
      result.v[i] = v[i] - a.v[i];
    return result;
  }

  Zvector operator * (ModuloRing val) {
    Zvector result(v.size());
    for(int i = 0; i < v.size(); i++)
      result.v[i] = v[i] * val;
    return result;
  }

  Zvector operator / (ModuloRing val) {
    Zvector result(v.size());
    for(int i = 0; i < v.size(); i++)
      result.v[i] = v[i] / val;
    return result;
  }
};

class IndependentSet{
  vector<Zvector> v;
  vector<int> rep;
public:
  Zvector _reduce(Zvector number){
    for(int i = 0; i < v.size(); i++)
      if(0 < number.v[rep[i]].number)
        number = number - v[i] * number.v[rep[i]];
    return number;
  }
  bool isnull(Zvector number) {
    for(int i = 0; i < number.v.size(); i++)
      if(0 < number.v[i].number)
        return 0;
    return 1;
  }
  bool _insert(Zvector number){
    number = _reduce(number);
    if(isnull(number) == 1)
      return 0;
    for(int i = 0; i < number.v.size(); i++)
      if(0 < number.v[i].number) {
        number = number / number.v[i].number;
        v.push_back(number);
        rep.push_back(i);
        return 1;
      }
    cout << "This is not supposed to happen\n";
    assert(2 < 1);
    return 0;
  }
};

int const moduloresult = 1000000007;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, len;
  cin >> n >> len;
  IndependentSet myset;
  int result = 1;
  for(int i = 1;i <= n; i++){
    string s;
    cin >> s;
    if(myset._insert(s) == 0)
      result = 1LL * result * 5 % moduloresult;
  }

  int q;
  cin >> q;
  for(int i = 1;i <= q; i++){
    string s;
    cin >> s;
    if(myset.isnull(myset._reduce(s)) == 1){
      cout << result << '\n';
    } else
      cout << 0 << '\n';
  }
  return 0;
}