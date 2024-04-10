#include <iostream>

const int MAX_W = 105;

using namespace std;

int hcount [MAX_W];
int vcount [MAX_W];

int main () {
  int width;
  cin >> width;

  char c;
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      cin >> c;
      if (c == 'C') {
	hcount[i]++;
	vcount[j]++;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < width; i++) {
    ans += hcount[i] * (hcount[i] - 1) / 2;
  }

  for (int i = 0; i < width; i++) {
    ans += vcount[i] * (vcount[i] - 1) / 2;
  }

  cout << ans << endl;
}