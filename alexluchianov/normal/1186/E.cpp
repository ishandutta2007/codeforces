#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
char v[1 + nmax][1 + nmax];
int sum[1 + nmax][1 + nmax];
int n, m;

ll getsum(ll x, ll y, ll n2, ll m2){
  if(x <= 0 || y <= 0)
    return 0;
  if(n2 == n && m2 == m)
    return sum[x][y];
  else if(x == n2)
    return n2 * y / 2;
  else if(y == m2)
    return x * m2 / 2;
  else {
    ll n3 = n2 / 2, m3 = m2 / 2;
    ll result = getsum(MIN(n3, x), MIN(m3, y), n3, m3);
    if(n3 < x)
      result += (x - n3) * MIN(m3, y) - getsum(x - n3, MIN(m3, y), n3, m3);
    if(m3 < y)
      result += MIN(n3, x) * (y - m3) - getsum(MIN(n3, x), y - m3, n3, m3);
    if(n3 < x && m3 < y)
      result += getsum(x - n3, y - m3, n3, m3);

    //cout << x << " " << y << " " << n2 << " " << m2 << " " << result << '\n';
    return result;
  }
}

int main()
{
  int q;
  cin >> n >> m >> q;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      cin >> v[i][j];
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + v[i][j] - '0';
  //*
  for(int i = 1;i <= q; i++){
    int x, y, x2, y2;
    cin >> x >> y >> x2 >> y2;
    cout << getsum(x2, y2, (1LL << 30) * n, (1LL << 30) * m) -
            getsum(x - 1, y2, (1LL << 30) * n, (1LL << 30) * m) -
            getsum(x2, y - 1, (1LL << 30) * n, (1LL << 30) * m) +
            getsum(x - 1, y - 1, (1LL << 30) * n, (1LL << 30) * m) << '\n';
  }
  //*/
  return 0;
}