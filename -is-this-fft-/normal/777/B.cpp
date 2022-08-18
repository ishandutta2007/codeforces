#include <iostream>

const int MAX_DIGIT = 10;
const int MAX_LEN = 1005;

using namespace std;

int sherlock [MAX_LEN], mortya [MAX_DIGIT], mortyb [MAX_DIGIT];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    char c;
    cin >> c;

    sherlock[i] = c - '0';
  }

  for (int i = 0; i < length; i++) {
    char c;
    cin >> c;
    
    mortya[c - '0']++;
    mortyb[c - '0']++;
  }

  int cnta = 0, cntb = 0;
  for (int i = 0; i < length; i++) {
    for (int j = sherlock[i]; true; j = (j + 1) % 10) {
      if (mortya[j] > 0) {
        mortya[j]--;
        if (j < sherlock[i]) {
          cnta++;
        }
        break;
      }
    }

    for (int j = (sherlock[i] + 1) % 10; true; j = (j + 1) % 10) {
      if (mortyb[j] > 0) {
        mortyb[j]--;
        if (j > sherlock[i]) {
          cntb++;
        }
        break;
      }
    }
  }

  cout << cnta << endl << cntb << endl;
}