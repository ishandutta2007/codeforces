#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
  cerr << "[";
  for (auto e : aux) cerr << e << ' ';
  cerr << "]";
  return cerr;
}

const int maxN = 100011;

int n, m, x, y;
int p[maxN], dim[maxN];

int find(int x) {
  if (p[x] == x) return x;
  p[x] = find(p[x]);
  return p[x];
}

bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return false;
  p[x] = y;
  dim[y] += dim[x];
  return true;
}

int main()
{
  //freopen("test.in", "r", stdin);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    p[i] = i, dim[i] = 1;

  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    merge(x, y);
  }

  for (int i = 1; i <= n; i++)
    if (p[i] == i)
      m -= dim[i] - 1;


  cout << max(0, m);


  return 0;
}