#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
string v[1 + nmax], v2[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, q;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    cin >> v[i - 1];
  for(int i = 1;i <= m; i++)
    cin >> v2[i - 1];
  cin >> q;
  for(int i = 1;i <= q; i++){
    int x;
    cin >> x;
    x--;
    cout << v[x % n] << v2[x % m] << '\n';
  }
  return 0;
}