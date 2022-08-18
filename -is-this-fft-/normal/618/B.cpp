#include <iostream>

const int MAX_W = 55;

using namespace std;

int main () {
  int width;
  cin >> width;

  bool vismax = false;
  for (int i = 0; i < width; i++) {
    int cur = 0;
    for (int j = 0; j < width; j++) {
      int el;
      cin >> el;
      cur = max(cur, el);
    }

    if (cur == width - 1 && !vismax) {
      cout << width << (i == width - 1 ? "\n" : " ");
      vismax = true;
    } else {
      cout << cur << (i == width - 1 ? "\n" : " ");
    }
  }
}