#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int gcd (int p, int q) {
  if (q == 0) {
    return p;
  } else {
    return gcd(q, p % q);
  }
}

const int MAX_L = 705;

int arr [MAX_L];
bool dp [MAX_L][MAX_L];
bool conn [MAX_L][MAX_L];
bitset<MAX_L> lends [MAX_L], rends [MAX_L];

int main () {
  ios::sync_with_stdio(false);
  
  int length;
  cin >> length;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= length; i++) {
    for (int j = 1; j <= length; j++) {
      if (gcd(arr[i], arr[j]) != 1) {
        conn[i][j] = 1;
      }
    }
  }

  for (int i = 1; i <= length; i++) {
    lends[i][i] = 1;
    rends[i][i] = 1;
  }
  
  for (int k = 1; k <= length; k++) {
    for (int i = 1; i + k <= length; i++) {
      int j = i + k;
      if (conn[i][j] && rends[i][j - 1]) {
        lends[j] |= lends[i];
      }
    }

    for (int i = length - k; i >= 1; i--) {
      int j = i + k;
      if (conn[i][j] && lends[j][i + 1]) {
        rends[i] |= rends[j];
      }
    }
  }

  for (int i = 1; i <= length; i++) {
    if (lends[i][1] && rends[i][length]) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}