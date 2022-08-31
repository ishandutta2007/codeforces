#include <iostream>
#define MAX_AB 100005
#define MODULUS 1000000007

using namespace std;

int a [MAX_AB], b [MAX_AB], n, k;
long long blockc [MAX_AB][10]; // blockc[i][j] is the amount of multiples of a[i] beginning w j
long long legn [MAX_AB]; // amount of legal blocks 

int main () {
  cin >> n >> k;
  for (int i = 0; i < n/k; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n/k; i++) {
    cin >> b[i];
  }

  int ten_to_k = 1;
  for (int i = 1; i <= k; i++) {
    ten_to_k *= 10;
  }
  
  for (int i = 0; i < n/k; i++) {
    long long counted = 0;
    for (int j = 0; j < 10; j++) {
      blockc[i][j] = (((ten_to_k/10)*(j+1)-1)/a[i]) + 1 - counted;
      counted += blockc[i][j];
      if (j != b[i]) legn[i] += blockc[i][j];
    }
  }

  long long sol = 1;
  for (int i = 0; i < n/k; i++) {
    sol *= legn[i];
    sol %= MODULUS;
  }

  cout << sol << endl;
  return 0;
}