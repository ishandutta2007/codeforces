#include <iostream>
#include <string>

typedef long long llong;

const int MAX_LEN = 1005;
const int ALPHABET = 26;
const int MOD = 1000000007;

using namespace std;

int chars [MAX_LEN];
int can [MAX_LEN][MAX_LEN];
int maxl [ALPHABET];
int minl [MAX_LEN];

llong ways [MAX_LEN];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    char c;
    cin >> c;

    chars[i] = c - 'a';
  }

  for (int i = 0; i < ALPHABET; i++) {
    cin >> maxl[i];
  }

  for (int i = 0; i < length; i++) {
    can[i][i + 1] = maxl[chars[i]];
    for (int j = i + 1; j < length; j++) {
      can[i][j + 1] = min(maxl[chars[j]], can[i][j]);
    }
  }
  
  ways[0] = 1;
  for (int i = 1; i <= length; i++) {
    for (int j = 0; j < i; j++) {
      if (can[j][i] >= i - j) {
        ways[i] += ways[j];
        ways[i] %= MOD;
      }
    }
  }

  cout << ways[length] << endl;

  int ans = 0;
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j <= length; j++) {
      if (can[i][j] >= j - i) {
        ans = max(ans, j - i);
      }
    }
  }

  cout << ans << endl;

  minl[0] = 0;
  for (int i = 1; i <= length; i++) {
    minl[i] = 1023456789;
    for (int j = 0; j < i; j++) {
      if (can[j][i] >= i - j) {
        minl[i] = min(minl[i], minl[j] + 1);
      }
    }
  }

  cout << minl[length] << endl;
}