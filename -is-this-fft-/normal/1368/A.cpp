#include <iostream>

using namespace std;

typedef long long ll;

int tryab (int a, int b, int n) {
  if (a > n || b > n) return 0;
  
  for (int i = 1; true; i += 2) {
    a += b;
    if (a > n || b > n) return i;
    b += a;
    if (a > n || b > n) return i + 1;    
  }
}

int tryba (int a, int b, int n) {
  if (a > n || b > n) return 0;
  
  for (int i = 1; true; i += 2) {
    b += a;
    if (a > n || b > n) return i;
    a += b;
    if (a > n || b > n) return i + 1;    
  }
}

void solve () {
  int a, b, n;
  cin >> a >> b >> n;

  cout << min(tryab(a, b, n), tryba(a, b, n)) << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}