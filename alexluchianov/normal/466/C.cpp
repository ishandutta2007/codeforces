#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
ll v[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    v[i] += v[i - 1];
  }
  if(0 != v[n] % 3) {
    cout << 0;
    return 0;
  }

  ll k = v[n] / 3;
  ll result = 0, sum = 0;
  for(int i = 1;i < n; i++){
    if(v[i] == 2 * k)
      result += sum;
    if(v[i] == k)
      sum++;
  }
  cout << result;
  return 0;
}