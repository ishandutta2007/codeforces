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

int t, a, b, c, d;

int main()
{
  //freopen("test.in", "r", stdin);

  cin >> t;
  for (int ti = 1; ti <= t; ti++) {
    cin >> a >> b >> c >> d;
    cout << b << ' ' << c << ' ' << c << '\n';
  }



  return 0;
}