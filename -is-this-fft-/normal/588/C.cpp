#include <iostream>

const int MAX_W = 1000050;

using namespace std;

int count [MAX_W];

int main () {
  ios::sync_with_stdio(false);
  
  int weightc;
  cin >> weightc;

  for (int i = 0; i < weightc; i++) {
    int weight;
    cin >> weight;
    count[weight]++;
  }

  for (int i = 0; i < MAX_W - 1; i++) {
    count[i + 1] += count[i] / 2;
    count[i] %= 2;
  }

  int ans = 0;
  for (int i = 0; i < MAX_W; i++) {
    if (count[i] != 0) {
      ans++;
    }
  }

  cout << ans << endl;
}