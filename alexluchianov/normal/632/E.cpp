#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using ll = long long;
using ld = long double;
ld const pi = acos(-1);

struct Complex{
  ld real;
  ld imag;
  Complex(ld real = 0, ld imag = 0){
    this->real = real;
    this->imag = imag;
  }
  Complex operator + (Complex a) {return {real + a.real, imag + a.imag};}
  Complex operator - (Complex a) {return {real - a.real, imag - a.imag};}
  Complex operator * (Complex a) {return {real * a.real - imag * a.imag, real * a.imag + imag * a.real}; }
  Complex operator / (int a) {return {real / a, imag / a};}
  void operator += (Complex a) {real += a.real; imag += a.imag;}
  void operator -= (Complex a) {real -= a.real; imag -= a.imag;}
  void operator /= (int a) {real /= a; imag /= a;}
};

int rev(int number, int p){
  int number2 = 0;
  for(int i = 0; i < p; i++)
    number2 |= ((0 < ((1 << i) & number)) << (p - 1 - i));
  return number2;
}

void fft(vector<Complex> &v, int inverse){
  int N = v.size();

  int p = 0;
  while((1 << p) < N)
    p++;

  for(int i = 0;i < N; i++){
    int pos = rev(i, p);
    if(i < pos)
      swap(v[i], v[pos]);
  }

  for(int jump = 2;jump <= N; jump *= 2){
    double const alpha = (2 * pi * inverse) / jump;
    Complex w(cos(alpha), sin(alpha));
    int halfjump = jump / 2;

    for(int i = 0; i < N; i += jump){
      Complex omega(1, 0);
      for(int j = i; j < i + halfjump; j++){
        Complex a = v[j], b = v[j + halfjump] * omega;

        v[j] = a + b;
        v[j + halfjump] = a - b;
        omega = omega * w;
      }
    }
  }

  if(inverse == -1)
    for(int i = 0;i < N; i++)
      v[i] /= N;
}

void multiply(vector<int> &a, vector<int> b){
  vector<Complex> sample_a, sample_b;
  int p = 0;
  while((1 << p) < a.size() + b.size())
    p++;
  sample_a.resize((1 << p));
  sample_b.resize((1 << p));
  for(int i = 0;i < a.size(); i++)
    sample_a[i] = a[i];
  for(int i = 0;i < b.size(); i++)
    sample_b[i] = b[i];
  fft(sample_a, 1);
  fft(sample_b, 1);
  for(int i = 0; i < sample_a.size(); i++)
    sample_a[i] = sample_a[i] * sample_b[i];

  fft(sample_a, -1);

  a.clear();
  for(int i = 0; i < sample_a.size(); i++)
    a.push_back(0 < int(sample_a[i].real + 0.5));
  while(0 < a.size() && 0 == a.back())
    a.pop_back();
}

int const nmax = 1000;

vector<int> lgpow(vector<int> a, int b){
  vector<int> result;
  result.push_back(1);
  for(int i = 0; (1 << i) <= b; i++){
    if(0 < (b & (1 << i)))
      multiply(result, a);
    multiply(a, a);
  }
  return result;
}

int main()
{
  //*
  ios::sync_with_stdio(0);
  cin.tie(0);
  //*/
  vector<int> products(1 + nmax, 0);
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    int a;
    cin >> a;
    products[a] = 1;
  }

  while(0 < products.size() && products.back() == 0)
    products.pop_back();

  vector<int> result = lgpow(products, k);

  for(int i = 0; i < result.size(); i++)
    if(0 < result[i])
      cout << i << " ";

  return 0;
}