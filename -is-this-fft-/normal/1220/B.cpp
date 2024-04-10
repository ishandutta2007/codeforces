#include <iostream>
#include <math.h>

using namespace std;

int gcd (int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

const int MAX_N = 1005;

typedef long long ll;

ll arr [MAX_N][MAX_N];

int main () {
  int height;
  cin >> height;

  int gc = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < height; j++) {
      cin >> arr[i][j];
    }
  }

  ll asq = arr[0][1] * arr[0][2] / arr[1][2];
  int a = sqrt(asq);
  cout << a;
  for (int i = 1; i < height; i++) {
    cout << " " << arr[0][i] / a;
  }
  cout << endl;
}