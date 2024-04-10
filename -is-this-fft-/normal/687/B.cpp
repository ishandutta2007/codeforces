#include <iostream>

using namespace std;

const int MAX_P = 1e6 + 5;

int factor [MAX_P];
int kmul [MAX_P];

void reduce (int x) {
  while (x != 1) {
    int f = factor[x];
    int mul = 0;
    while (x % f == 0) {
      x /= f;
      mul++;
    }

    if (mul >= kmul[f]) {
      kmul[f] = 0;
    }
  }
}

int main () {
  for (int i = 2; i < MAX_P; i++) {
    if (factor[i] == 0) {
      for (int j = i; j < MAX_P; j += i) {
        factor[j] = i;
      }
    }
  }
  
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;

  while (k != 1) {
    kmul[factor[k]]++;
    k /= factor[k];
  }
  
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    reduce(x);
  }

  bool ok = 1;
  for (int i = 0; i < MAX_P; i++) {
    if (kmul[i] != 0) ok = 0;
  }

  if (ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
}