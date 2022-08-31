#include <iostream>
#include <vector>

using namespace std;

const int MAX_L = 150005;

int length;
int arr [MAX_L], brr [MAX_L];

bool is_wcd (int num) {
  for (int i = 0; i < length; i++) {
    if (arr[i] % num != 0 && brr[i] % num != 0) {
      return false;
    }
  }
  return true;
}

const int MAX_P = 100005;
bool composite [MAX_P];

int main () {
  composite[0] = 1;
  composite[1] = 1;
  for (int i = 2; i < MAX_P; i++) {
    if (!composite[i]) {
      for (int j = 2 * i; j < MAX_P; j += i) {
        composite[j] = 1;
      }
    }
  }
  
  cin >> length;
  for (int i = 0; i < length; i++) {
    cin >> arr[i] >> brr[i];
  }

  vector<int> adivs;
  for (int i = 2; i < MAX_P; i++) {
    if (arr[0] % i == 0 && !composite[i]) {
      adivs.push_back(i);
    }
  }

  int a = arr[0];
  for (int div : adivs) {
    while (a % div == 0) {
      a /= div;
    }
  }
  if (a > 1) {
    adivs.push_back(a);
  }

  vector<int> bdivs;
  for (int i = 2; i < MAX_P; i++) {
    if (brr[0] % i == 0 && !composite[i]) {
      bdivs.push_back(i);
    }
  }

  int b = brr[0];
  for (int div : bdivs) {
    while (b % div == 0) {
      b /= div;
    }
  }

  if (b > 1) {
    bdivs.push_back(b);
  }

  int ans = -1;
  for (int x : adivs) {
    if (is_wcd(x)) {
      ans = x;
    }
  }
  for (int x : bdivs) {
    if (is_wcd(x)) {
      ans = x;
    }
  }

  cout << ans << endl;
}