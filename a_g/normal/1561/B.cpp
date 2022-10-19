#include <math.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void solve (int a, int b);

int main () {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    solve(a, b);
  }
}

void solve (int a, int b) {
  int n = a+b;
  int k = n/2;
  int min, max;
  if (a <= k) {
    max = a+n-k;
    min = k-a;
  }
  else {
    max = n-k+b;
    min = k-b;
  }
  int step = 2 - (n & 1);
  cout << (max-min)/step+1 << endl;
  for (int j = min; j <= max; j += step) {
    cout << j << " ";
  }
  cout << endl;
}