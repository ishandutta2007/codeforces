#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const modulo = 998244353;
int const root = 3;

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else{
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int rev(int n, int p){
  int result = 0;
  for(int i = 0; i < p; i++)
    if(0 < (n & (1 << i)))
      result += (1 << (p - 1 - i));
  return result;
}

///length of v should be a power of 2

void NTT(vector<int> &v, int inverse){
  int n = v.size(), p = 0;
  while((1 << p) < n)
    p++;
  assert((1 << p) == n);

  for(int i = 0;i < n; i++)
    if(i < rev(i, p))
      swap(v[i], v[rev(i, p)]);

  int r = root;
  if(inverse == -1)
    r = lgpow(r, modulo - 2);

  int inv2 = lgpow(2, modulo - 2);

  for(int jump = 2; jump <= n; jump *= 2){
    int half = jump / 2;

    for(int i = 0;i < n; i += jump){
      int omega = lgpow(r, modulo / jump), alpha = 1;
      for(int j = i; j < i + half; j++){
        int a = v[j], b = 1LL * alpha * v[j + half] % modulo;

        v[j] = a + b;
        if(modulo <= v[j])
          v[j] -= modulo;

        v[j + half] = a - b;
        if(v[j + half] < 0)
          v[j + half] += modulo;

        alpha = 1LL * alpha * omega % modulo;
      }
    }
  }

  if(inverse == -1) {
    int invn = lgpow(n, modulo - 2);
    for(int i = 0; i < n; i++)
      v[i] = 1LL * v[i] * invn % modulo;
  }
}

int h[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> h[i];

  int exp = 0, result = 1;
  for(int i = 1;i <= n; i++){
    if(h[i] != h[i % n + 1])
      exp++;
    else
      result = 1LL * result * k % modulo;
  }
  vector<int> v;
  int p = 0;
  while((1 << p) < n)
    p++;
  v.resize((1 << p) * 2);
  v[0] = 1;
  v[1] = (k - 2);
  v[2] = 1;

  NTT(v, 0);
  //*
  for(int i = 0; i < v.size(); i++)
    v[i] = lgpow(v[i], exp);
  //*/

  NTT(v, -1);
  int sum = 0;
  for(int i = exp + 1; i < v.size(); i++) {
    sum += 1LL * result * v[i] % modulo;
    if(modulo < sum)
      sum -= modulo;
  }
  cout << sum;
  return 0;
}