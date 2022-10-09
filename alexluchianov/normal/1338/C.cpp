#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const lgmax = 60;
int frec[1 + nmax];

ll eval(ll n){
  for(int i = 0; i < lgmax; i += 2){
    if(n <= (1LL << i)){
      return ((1LL << i) + n - 1);
    } else
      n -= (1LL << i);
  }
  return 0;
}

ll rev(ll n){
  ll result = 0;
  for(int i = 0; i < lgmax; i += 2){
    ll bit1 = (0 < (n & (1LL << i)));
    ll bit2 = (0 < (n & (1LL << (i + 1))));
    if(bit1 == 1 && bit2 == 0){
      bit1 = 0;
      bit2 = 1;
    } else if(bit1 == 0 && bit2 == 1){
      bit1 = 1;
      bit2 = 1;
    } else if(bit1 == 1 && bit2 == 1){
      bit1 = 1;
      bit2 = 0;
    }
    result |= (bit1 << i);
    result |= (bit2 << (i + 1));
  }
  return result;
}

ll eval2(ll n){
  for(int i = 1; i < lgmax; i += 2){
    if(n <= (1LL << (i - 1))){
      return ((1LL << (i)) + rev(n - 1));
    } else
      n -= (1LL << (i - 1));
  }
  return 0;
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  /*
  int n = 100;
  int step = 1;
  for(int i = 1;i <= n; i++){
    for(int j = 1; j <= nmax; j++)
      if(frec[j] == 0){
        frec[j] = 1;
        for(int j2 = 1; j2 <= nmax; j2++)
          if(frec[j2] == 0 && frec[j ^ j2] == 0) {
            cout << j << " " << j2 << '\n';
            cout << eval(step) << " " << eval2(step) << '\n';
            frec[j2] = frec[j ^ j2] = 1;
            break;
          }
        step++;
        cout << '\n';
      }
  }
  //*/
  int q;
  cin >> q;
  for(int i = 1;i <= q; i++){
    ll n;
    cin >> n;
    n--;
    if(n % 3 == 0){
      cout << eval(1 + n / 3) << '\n';
    } else if(n % 3 == 1){
      cout << eval2(1 + n / 3) << '\n';
    } else
      cout << (eval(1 + n / 3) ^ eval2(1 + n / 3)) << '\n';
  }
  return 0;
}