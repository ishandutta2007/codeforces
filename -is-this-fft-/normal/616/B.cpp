#include <iostream>

const int MAX_W = 105;
const int INF = 1023456789;

using namespace std;

int price [MAX_W][MAX_W];
int cheapest [MAX_W];

int main () {
  int height, width;
  cin >> height >> width;

  int bestrow = 0, bestcol = INF;
  for (int i = 0; i < height; i++) {
    int cheapest = INF;
    for (int j = 0; j < width; j++) {
      int price;
      cin >> price;
      cheapest = min(cheapest, price);
    }
    bestrow = max(bestrow, cheapest);
  }

  cout << bestrow << endl;
}