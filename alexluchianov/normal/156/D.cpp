#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = 100000;
int modulo;

class DSU{
private:
  vector<int> mult;
  vector<int> sz;
public:
  DSU(int n){
    mult.resize(1 + n);
    sz.resize(1 + n);
    for(int i = 1;i <= n; i++)
      mult[i] = i;
    for(int i = 1;i <= n; i++)
      sz[i] = 1;
  }
  int jump(int gala){
    if(gala != mult[gala])
      mult[gala] = jump(mult[gala]);
    return mult[gala];
  }
  bool unite(int gala, int galb){
    gala = jump(gala);
    galb = jump(galb);
    if(mult[gala] == mult[galb])
      return 0;
    if(sz[galb] < sz[gala])
      swap(gala, galb);
    mult[gala] = galb;
    sz[galb] += sz[gala];
    sz[gala] = 0;
    return 1;
  }
  int getsz(int gala){
    return sz[gala];
  }
};

int lgpow(int a, int b){
  if(b == 0)
    return 1 % modulo;
  else if(b == 1)
    return a % modulo;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m >> modulo;
  int k = n;
  DSU myset(n);

  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    k -= myset.unite(x, y);
  }

  if(k == 1) {
    cout << 1 % modulo;
  } else {
    int result = 1;
    for(int i = 1;i <= n; i++)
      if(0 < myset.getsz(i))
        result = 1LL * result * myset.getsz(i) % modulo;
    cout << 1LL * result * lgpow(n, k - 2) % modulo;
  }
  return 0;
}