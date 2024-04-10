#include <iostream>
#include <iomanip>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = (1 << 18);
ld v[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;
  ld result = 0;
  for(int i = 0;i < (1 << n); i++){
    cin >> v[i];
    result += v[i];
  }
  cout << setprecision(6) << fixed << result / (1 << n) << '\n';
  for(int i = 0; i < q; i++){
    int x, val;
    cin >> x >> val;
    result -= v[x];
    v[x] = val;
    result += val;
    cout << setprecision(6) << fixed << result / (1 << n) << '\n';
  }
  return 0;
}