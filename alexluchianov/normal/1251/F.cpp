
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

using ll = long long;
using ld = long double;

int const nmax = 300000;
int const modulo = 998244353;
int const root = 3;

int rev(int number, int p){
  int number2 = 0;
  for(int i = 0; i < p; i++)
    number2 |= ((0 < ((1 << i) & number)) << (p - 1 - i));
  return number2;
}

int lgput(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgput(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

void ntt(vector<int> &v, int inverse){
  int N = v.size();

  int p = 0;
  while((1 << p) < N)
    p++;

  for(int i = 0;i < N; i++){
    int pos = rev(i, p);
    if(i < pos)
      swap(v[i], v[pos]);
  }

  int r = root;
  if(inverse == -1)
    r = lgput(root, modulo - 2);
  for(int jump = 2;jump <= N; jump = jump * 2 ){
    int w = lgput(r, modulo / jump);
    int halfjump = (jump >> 1);

    for(int i = 0; i < N; i += jump){
      int omega = 1;
      for(int j = i; j < i + halfjump; j++){
        int a = v[j], b = 1LL * v[j + halfjump] * omega % modulo;

        v[j] = a + b;
        if(modulo <= v[j])
          v[j] -= modulo;

        v[j + halfjump] = (modulo + a - b);
        if(modulo <= v[j + halfjump])
          v[j + halfjump] -= modulo;

        omega = 1LL * omega * w % modulo;
      }
    }
  }
  if(inverse == -1) {
    int inv = lgput(N, modulo - 2);
    for(int i = 0;i < N; i++)
      v[i] = 1LL * v[i] * inv % modulo;
  }
}

void multiply(vector<int> &a, vector<int> b){
  vector<int> sample_a, sample_b;
  int p = 0;
  while((1 << p) < a.size() + b.size())
    p++;
  sample_a.resize((1 << p));
  sample_b.resize((1 << p));
  for(int i = 0;i < a.size(); i++)
    sample_a[i] = a[i];
  for(int i = 0;i < b.size(); i++)
    sample_b[i] = b[i];
  ntt(sample_a, 1);
  ntt(sample_b, 1);
  for(int i = 0; i < sample_a.size(); i++)
    sample_a[i] = 1LL * sample_a[i] * sample_b[i] % modulo;

  ntt(sample_a, -1);

  a.clear();
  for(int i = 0; i < sample_a.size(); i++)
    a.push_back(sample_a[i]);
  while(0 < a.size() && 0 == a.back())
    a.pop_back();
}

vector<int> lgpow(vector<int> a, int b){
  a.resize(a.size() * b);
  int p = 0;
  while((1 << p) < a.size())
    p++;
  a.resize(1 << p);
  ntt(a, 1);
  for(int i = 0; i < a.size(); i++)
    a[i] = lgput(a[i], b);
  ntt(a, -1);

  return a;
}

int v[1 + nmax];
unordered_map<int,int> frec;
int v2[1 + nmax];
int fact[1 + nmax];

int comb(int n, int k){
  int result = fact[n];
  int result2 = 1LL * fact[k] * fact[n - k] % modulo;
  return 1LL * result * lgput(result2, modulo - 2) % modulo;
}

int main()
{
  fact[0] = 1;
  for(int i = 1; i <= nmax; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;

  //*
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //*/
  int n, k;
  cin >> n >> k;

  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    frec[v[i]]++;
  }
  sort(v + 1, v + n + 1);

  for(int i = 1;i <= k; i++)
    cin >> v2[i];

  vector<int> sol[6];
  for(int i = 1;i <= k; i++) {
    sol[k].push_back(1);
    int scount1 = 0, scount2 = 0;
    for(int j = 1; j <= n; j++)
      if(v[j - 1] != v[j] && v[j] < v2[i]) {
        if(frec[v[j]] == 1)
          scount1++;
        else
          scount2++;
      }
    vector<int> solpart(1 + scount2 * 2);
    sol[i].resize(1 + scount1);
    for(int j = 0;j <= scount1; j++)
      sol[i][j] = 1LL * comb(scount1, j) * lgput(2, j) % modulo;

    for(int j = 0; j <= 2 * scount2; j++)
      solpart[j] = 1LL * comb(scount2 * 2, j) % modulo;

    multiply(sol[i], solpart);
  }

  int q;
  cin >> q;
  for(int i = 1;i <= q; i++){
    int a, result = 0;
    cin >> a;
    for(int h = 1; h <= k; h++) {
      int pos = a / 2 - v2[h] - 1;
      if(0 <= pos && pos < sol[h].size()) {
        result += sol[h][pos];
        if(modulo <= result)
          result -= modulo;
      }
    }
    cout << result << '\n';
  }
  return 0;
}