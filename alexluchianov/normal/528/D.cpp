#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

class Complex{
public:
  double real, imag;
  Complex(double x = 0) {real = x; imag = 0;};
  Complex(double x, double y) {real = x ; imag = y;};
  Complex operator + (Complex const &a) const{return {real + a.real , imag + a.imag};};
  Complex operator - (Complex const &a) const{return {real - a.real , imag - a.imag};};
  Complex operator * (Complex const &a) const{return {real * a.real - imag * a.imag, imag * a.real + a.imag * real};};
  Complex operator / (int const &a) const {return {real / a , imag / a};};
};

int const nmax = 200000;
double const pi = acos(-1);

int rev(int pos , int p){
  int result = 0;
  for(int i = 0 ; i < p ; i++)
    result |= ((0 < (pos & (1 << i))) << (p - 1 - i));
  return result;
}

void fft(vector<Complex> &a , double inverse) {
  int n = a.size() , p = 0;
  while((1 << p) < n)
    p++;

  for(int i = 0 ; i < n ; i++){
    int pos = rev(i , p);
    if(i < pos)
      swap(a[i] , a[pos]);
  }

  for(int jump = 2 ; jump <= n ; jump *= 2){
    for(int i = 0 ; i < n ; i += jump){
      double alpha = 2 * pi * inverse / jump;
      Complex init(1.0) , omega(cos(alpha) , sin(alpha));

      for(int h = i ; h < i + jump / 2 ; h++ , init = init * omega){
        Complex last = init * a[h + jump / 2];
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

void multiply(vector<Complex> &a , vector<Complex> b){
  int p = 0;
  while((1 << p) < a.size() || (1 << p) < b.size())
    p++;
  a.resize(1 << p);
  b.resize(1 << p);
  fft(a , 1);
  fft(b , 1);
  for(int i = 0 ; i < a.size() ; i++)
    a[i] = a[i] * b[i];
  fft(a , -1);
  for(int i = 0 ; i < a.size() ; i++){
    a[i].imag = 0;
    a[i].real = (int)(a[i].real + 0.5);
  }

}

vector<Complex> build(string s , char c){
  vector<Complex> result(s.size(), 0);
  for(int i = 0 ; i < s.size() ; i++)
    result[i] = s[i] == c;
  return result;
}

vector<Complex> buildcanmet(string s, char c , int k){
  vector<Complex> result(s.size() , 0);
  int st = -k -5;
  for(int i = 0 ; i < s.size() ; i++){
    if(s[i] == c)
      st = i;
    if(i - k <= st)
      result[i] = 1;
  }
  int dr = s.size() + k + 5;
  for(int i = s.size() - 1 ; 0 <= i ; i--){
    if(s[i] == c)
      dr = i;
    if(dr <= i + k)
      result[i] = 1;
  }
  return result;
}

int main()
{
  string s, t;
  int k;
  cin >> k >> k >> k;
  cin >> s >> t;
  reverse(t.begin() , t.end());

  vector<Complex> p1a , p2a , p1g , p2g , p1c , p2c , p1t , p2t;
  p2a = build(t , 'A');
  p1a = buildcanmet(s , 'A' , k);
  multiply(p1a , p2a);

  p2g = build(t , 'G');
  p1g = buildcanmet(s , 'G' , k);
  multiply(p1g , p2g);

  p2t = build(t , 'T');
  p1t = buildcanmet(s , 'T' , k);
  multiply(p1t , p2t);

  p2c = build(t , 'C');
  p1c = buildcanmet(s , 'C' , k);
  multiply(p1c , p2c);
  int result = 0;
  for(int i = t.size() - 1; i < p1c.size() ; i++) {
    //cout << p1a[i].real << " " << p1g[i].real << " " << p1t[i].real << " " << p1c[i].real << '\n';

    if(p1a[i].real + p1g[i].real + p1t[i].real + p1c[i].real == t.size())
      result++;
  }
  cout << result;

  return 0;
}