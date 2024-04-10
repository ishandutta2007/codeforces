#include <iostream>
#define MAX_C 100005

using namespace std;

int mins [MAX_C], maxs [MAX_C]; // min and max member castle between 1 and i
int mine [MAX_C], maxe [MAX_C]; // min and max member castle between i and oo
int height [MAX_C];

int main () {
  int castlec;
  cin >> castlec;
  for (int i = 1; i <= castlec; i++) {
    cin >> height[i];
  }

  mins[1] = height[1];
  maxs[1] = height[1];
  for (int i = 2; i <= castlec; i++) {
    mins[i] = min(mins[i-1], height[i]);
    maxs[i] = max(maxs[i-1], height[i]);
  }

  mine[castlec] = height[castlec];
  maxe[castlec] = height[castlec];
  for (int i = castlec-1; i > 0; i--) {
    mine[i] = min(mine[i+1], height[i]);
    maxe[i] = max(maxe[i+1], height[i]);
  }

  int blockc = 1;
  for (int i = 1; i < castlec; i++) {
    if (maxs[i] <= mine[i+1]) {
      blockc++;
    }
  }

  cout << blockc << endl;
}