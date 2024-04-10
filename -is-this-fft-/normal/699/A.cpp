#include <iostream>
#include <string>
#include <vector>

const int INF = 1023456789;

using namespace std;

int main () {
  int particlec;
  cin >> particlec;

  string dir;
  cin >> dir;

  vector<int> locations (particlec);
  for (int i = 0; i < particlec; i++) {
    cin >> locations[i];
  }

  int best = INF;
  for (int i = 0; i < particlec - 1; i++) {
    if (dir[i] == 'R' && dir[i + 1] == 'L') {
      best = min(best, (locations[i + 1] - locations[i]) / 2);
    }
  }

  cout << (best == INF ? -1 : best) << endl;
}