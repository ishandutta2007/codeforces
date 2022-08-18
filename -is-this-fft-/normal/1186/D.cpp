#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;
const double eps = 1e-6;

double a [MAX_N];
int b [MAX_N];
int is_int [MAX_N];

int lower (double d) {
  if (d < 0) return (int) (d - 1 + eps);
  return (int) d;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = lower(a[i]);
    if (abs(a[i] - (double) b[i]) < eps) {
      is_int[i] = 1;
    }
    sum += b[i];
  }
  
  for (int i = 0; i < n; i++) {
    if (sum < 0 && !is_int[i]) {
      b[i]++;
      sum++;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << b[i] << '\n';
  }
}