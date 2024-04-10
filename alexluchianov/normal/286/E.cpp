#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
double const pi = acos(-1);

class Complex{
public:
  double real, imag;
  Complex(double x = 0){real = x; imag = 0;};
  Complex(double x, double y) {real = x; imag = y;};
  Complex operator + (Complex const &a) const {return {real + a.real , imag + a.imag};};
  Complex operator - (Complex const &a) const {return {real - a.real , imag - a.imag};};
  Complex operator * (Complex const &a) const {return {real * a.real - imag * a.imag , real * a.imag + a.real * imag};};
  Complex operator / (double const &a) const {return {real / a , imag / a};};
};

int rev(int pos , int p){
  int result = 0;
  for(int i = 0 ; i < p ; i++)
    result |= ((0 < ((1 << i) & pos)) << (p - i - 1));
  return result;
}

void fft(vector<Complex> &a , double inverse){
  int n = a.size(), p = 0;
  while((1 << p) < n)
    p++;

  for(int i = 0 ; i < n ; i++){
    int pos = rev(i , p);
    if(i < pos)
      swap(a[i] , a[pos]);
  }

  for(int jump = 2 ; jump <= n ; jump *= 2){
    for(int j = 0 ; j < n ; j += jump){
      double alpha = pi * 2 * inverse / jump;
      Complex init(1.0) , omega(cos(alpha) , sin(alpha));

      for(int h = j ; h < j + jump / 2 ; h++ , init = init * omega){
        Complex last = a[h + jump / 2] * init;
        a[h + jump / 2] = a[h] - last;
        a[h] = a[h] + last;
        if(inverse == -1){
          a[h] = a[h] / 2;
          a[h + jump / 2] = a[h + jump / 2] / 2;
        }
      }
    }
  }
}

void multiply(vector<Complex> &a , vector<Complex> &b){
  int p = 0;
  while((1 << p) < a.size() || (1 << p) < b.size())
    p++;

  p++;
  a.resize(1 << p);
  b.resize(1 << p);
  fft(a , 1);
  fft(b , 1);
  for(int i = 0 ; i < a.size() ; i++)
    a[i] = a[i] * b[i];
  fft(a , -1);

  for(int i = 0 ; i < a.size() ; i++) {
    a[i].imag = 0;
    a[i].real = (int)(a[i].real + 0.5);
  }
}

int main()
{
  int n , m;
  cin >> n >> m;
  vector<Complex> vinit(1 + m, {0, 0}), v(1 + m , {0 , 0}) , v2(1 + m , {0 , 0});
  for(int i = 1 ; i <= n ; i++){
    int a;
    cin >> a;
    v[a] = 1;
  }
  vinit = v;
  v2 = v;
  multiply(v, v2);
  int scount = 0;

  for(int i = 1 ; i <= m ; i++){
    if(vinit[i].real == 0 && 0 < v[i].real) {
      cout << "NO";
      return 0;
    } else if(vinit[i].real == 1 && 0 == v[i].real)
      scount++;
  }

  cout << "YES\n";
  cout << scount << '\n';
  for(int i = 1 ; i <= m ; i++){
    if(vinit[i].real == 1 && 0 == v[i].real)
      cout << i << " ";
  }
  return 0;
}