#include <iostream>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 200000;
int const lgmax = 30;
ll b[1 + nmax], c[1 + nmax], v[1 + nmax];
int bits[1 + lgmax];

bool check(int n){
  for(int i = 1;i <= n; i++)
    for(int h = 0; h <= lgmax; h++)
      if(0 < ((1 << h) & v[i]))
        bits[h]++;
  for(int i = 1; i <= n; i++){
    for(int h = 0; h <= lgmax; h++){
      if(0 < ((1 << h) & v[i])){
        b[i] -= bits[h] * (1LL << h);
        c[i] -= n * (1LL << h);
      } else
        c[i] -= bits[h] * (1LL << h);
    }
  }
  bool valid = 1;
  for(int i = 1;i <= n; i++)
    valid &= ((0 == b[i]) & (0 == c[i]));
  return valid;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  ll sum = 0;
  for(int i = 1; i <= n; i++)
    cin >> b[i];
  for(int i = 1; i <= n; i++)
    cin >> c[i];
  for(int i = 1;i <= n ;i++)
    sum += b[i] + c[i];
  sum = sum / 2 / n;
  for(int i = 1;i <= n; i++)
    v[i] = (b[i] + c[i] - sum) / n;
  if(check(n))
    for(int i = 1;i <= n; i++)
      cout << v[i] << " ";
  else
    cout << -1;
  return 0;
}