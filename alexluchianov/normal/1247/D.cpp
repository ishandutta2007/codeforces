#include <iostream>
#include <map>

using namespace std;

using ll = long long;

int const nmax = 100000;
int v[1 + nmax];

ll pow(int a, int b){
  ll number = 1;
  for(int i = 1;i <= b; i++) {
    number = number * a;
    if(nmax < number)
      return 1 + nmax;
  }
  return number;
}

ll form(ll number, int k){
  ll mask = 1;
  for(int i = 2;i * i <= number; i++){
    if(number % i == 0){
      int scount = 0;
      while(number % i == 0){
        scount++;
        number /= i;
      }
      mask = mask * pow(i, scount % k);
    }
  }
  if(1 < number){
    mask = mask * pow(number, 1);
    if(nmax < mask)
      return nmax + 1;
  }
  return mask;
}

ll antiform(ll number, int k){
  ll mask = 1;
  for(int i = 2;i * i <= number; i++){
    if(number % i == 0){
      int scount = 0;
      while(number % i == 0){
        scount++;
        number /= i;
      }
      mask = mask * pow(i, (k - scount % k) % k);
      if(nmax < mask)
        return nmax + 1;
    }
  }
  if(1 < number){
    mask = mask * pow(number, k - 1);
    if(nmax < mask)
      return nmax + 1;
  }
  return mask;
}

int frec[5 + nmax];

int main()
{
  int n, k;
  cin >> n >> k;
  ll result = 0;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    result += frec[antiform(v[i], k)];
    frec[form(v[i], k)]++;
    //cout << form(v[i], k) << " " << antiform(v[i], k) << '\n';
  }
  cout << result;
  return 0;
}