#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const valmax = 1000000;

int const modulo = 1000000007;

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
int invmod(int a, int modulo){
  int x, y;
  gcd(a, modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return x;
}

int v[1 + nmax];

bitset<1 + valmax> ciur;
vector<int> primes;

void computeprimes(){
  ciur[1] = 1;
  for(int i = 2; i * i <= valmax; i++) {
    if(ciur[i] == 0)
      for(int j = i * i; j <= valmax; j += i)
        ciur[j] = 1;
  }
  for(int i = 1;i <= valmax; i++)
    if(ciur[i] == 0)
      primes.push_back(i);
}

vector<pair<int,int>> query[1 + nmax];
int last[1 + valmax];

class SegmentTree{
private:
  vector<int> aint;
public:
  SegmentTree(int n){
    aint.resize(4 * n);
  }
  void build(int node, int from, int to){
    aint[node] = 1;
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
    }
  }
  void update(int node, int from, int to, int x, int y, int val){
    if(from == x && to == y)
      aint[node] = 1LL * aint[node] * val % modulo;
    else {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, MIN(mid, y), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
    }
  }
  int query(int node, int from, int to, int x){
    if(from < to){
      int mid = (from + to) / 2;
      int result = aint[node];
      if(x <= mid)
        return 1LL * result * query(node * 2, from, mid, x) % modulo;
      else
        return 1LL * result * query(node * 2 + 1, mid + 1, to, x) % modulo;
    } else
      return aint[node];
  }
};

void updateprime(int pos, int val, int n, SegmentTree &aint){
  int coef = (modulo + 1LL - invmod(val, modulo)) % modulo;
  aint.update(1, 1, n, pos, last[val] - 1, coef);
  last[val] = pos;
}

void update(int pos, int n, SegmentTree &aint){
  for(int i = 0; i < primes.size() && primes[i] * primes[i] <= v[pos]; i++){
    if(v[pos] % primes[i] == 0){
      updateprime(pos, primes[i], n, aint);
      while(v[pos] % primes[i] == 0)
        v[pos] /= primes[i];
    }
  }
  if(1 < v[pos])
    updateprime(pos, v[pos], n, aint);
}
int sol[1 + nmax], pref[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n;
  computeprimes();
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= valmax; i++)
    last[i] = n + 1;

  cin >> m;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    query[x].push_back({i, y});
  }

  pref[0] = 1;
  for(int i = 1;i <= n; i++)
    pref[i] = 1LL * pref[i - 1] * v[i] % modulo;

  SegmentTree aint(n);
  aint.build(1, 1, n);

  for(int i = n;1 <= i; i--){
    update(i, n, aint);
    for(int h = 0; h < query[i].size(); h++){
      int y = query[i][h].second;
      sol[query[i][h].first] = 1LL * pref[y] * invmod(pref[i - 1], modulo) % modulo * aint.query(1, 1, n, y) % modulo;
    }
  }
  for(int i = 1;i <= m; i++)
    cout << sol[i] << '\n';
  return 0;
}