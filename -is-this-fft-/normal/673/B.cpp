#include <iostream>

const int INF = 1023456789;

using namespace std;

int main () {
  int maxeasy = 0, minhard = INF;

  int problemc, pairc;
  cin >> problemc >> pairc;
  
  for (int i = 0; i < pairc; i++) {
    int u, v;
    cin >> u >> v;

    if (u > v) {
      swap(u, v);
    }

    maxeasy = max(maxeasy, u);
    minhard = min(minhard, v);
  }

  if (pairc == 0) {
    cout << problemc - 1 << endl;
  } else if (maxeasy > minhard) {
    cout << 0 << endl;
  } else {
    cout << minhard - maxeasy << endl;
  }
}