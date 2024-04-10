#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000000;
int const modulo = 998244353;
int v[1 + nmax];
int real[1 + nmax];
int ind = 0;

void dfs(int parity, int level){
  if(1 <= level)
    dfs(-parity, level - 1);
  ++ind;
  v[ind] = parity;
  if(0 < level)
    real[ind] = 1;
  else
    real[ind] = 0;

  if(1 <= level)
    dfs(parity, level - 1);
}
int fact[1 + nmax];

void computefact(){
  fact[0] = 1;
  for(int i = 1;i <= nmax; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
}

void gcd(int a, int b, int &x, int &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x, y);
    int aux = x;
    x = y;
    y = aux - a / b * y;
  }
}

int comb(int n, int k){
  if(n < k)
    return 0;
  ll result = fact[n];
  ll result2 = 1LL * fact[k] * fact[n - k] % modulo;
  int x, y;
  gcd(result2, modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return 1LL * result * x % modulo;
}

int main()
{
  computefact();

  int n, p, level;
  cin >> n;
  p = 1;
  level = 1;
  while(p * 2 + 1 <= n) {
    p = p * 2 + 1;
    level++;
  }
  if(n % 2 == 0)
    dfs(-1, level);
  else
    dfs(1, level);
  v[0] = -1;
  real[0] = 1;
  int sleft = n - p, schoose = 0;
  /*
  cout << p << " " << level << '\n';
  for(int i = 0;i <= ind; i++)
    cout << v[i] << " ";
  cout << '\n';
  for(int i = 0;i <= ind; i++)
    cout << real[i] << " " ;
  cout << '\n';
  //*/
  //cout << schoose << " " << sleft << '\n';

  for(int i = 1;i <= ind; i++){
    if(real[i] == 1){
      if(real[i - 1] == 1) {
        if(v[i - 1] != - v[i]) {
          cout << 0;
          return 0;
        }
      } else if(real[i - 2] == 1){
        if(v[i - 2] == -v[i])
          continue;
        else if(v[i - 1] == -v[i]){
          sleft--;
        } else{
          cout << 0;
          return 0;
        }
      } else if(real[i - 3] == 1){
        if(v[i - 3] == -v[i]){
          if(v[i - 3] == -v[i - 2] && v[i - 2] == -v[i - 1])
            schoose++;
        } else if(v[i - 3] == -v[i - 2] || v[i - 3] == -v[i - 1])
          sleft--;
        else {
          cout << 0;
          return 0;
        }
      } else {
        cout << "I don't know how we got here\n";
        return 0;
      }
    }
  }

  //cout << schoose << " " << sleft << '\n';
  if(sleft < 0)
    cout << 0;
  else if(sleft % 2 == 0)
    cout << comb(schoose, sleft / 2);
  else
    cout << 0;

  return 0;
}