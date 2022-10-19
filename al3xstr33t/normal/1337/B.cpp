#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
  cerr << "[";
  for (auto e : aux) cerr << e << ' ';
  cerr << "]";
  return cerr;
}

int t, x, n, m;

int main()
{
  //freopen("test.in", "r", stdin);

  cin >> t;
  for (int ti = 1; ti <= t; ti++) {
    cin >> x >> n >> m;

    while (n + m > 0 && x >= 1) {
      int aux = (x / 2) + 10;
      if (n > 0 && aux < x) {
        x = aux;
        n--;
      } else {
        if (m > 0) {
          x -= 10;
          m--;
        } else {
          break;
        }
      }
    }

    if (x <= 0) 
      cout << "YES\n";
    else
      cout << "NO\n";
  }


  return 0;
}