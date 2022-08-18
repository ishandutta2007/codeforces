#include <iostream>
#include <set>

using namespace std;

const int MAX_SHIRT = 200005;
const int MAX_COLOR = 5;

struct shirt {
  int price, front, back;
} shirts [MAX_SHIRT];

bool operator< (shirt p, shirt q) {
  return p.price < q.price;
}

set<shirt> colors [MAX_COLOR];

int main () {
  ios::sync_with_stdio(false);

  int shirtc;
  cin >> shirtc;

  for (int i = 0; i < shirtc; i++) {
    cin >> shirts[i].price;
  }

  for (int i = 0; i < shirtc; i++) {
    cin >> shirts[i].front;
  }

  for (int i = 0; i < shirtc; i++) {
    cin >> shirts[i].back;
  }

  for (int i = 0; i < shirtc; i++) {
    colors[shirts[i].front].insert(shirts[i]);
    colors[shirts[i].back].insert(shirts[i]);
  }

  int custc;
  cin >> custc;

  for (int i = 0; i < custc; i++) {
    int fav;
    cin >> fav;

    if (colors[fav].empty()) {
      cout << -1 << ' ';
    } else {
      shirt sel = *colors[fav].begin();
      cout << sel.price << ' ';

      colors[sel.front].erase(sel);
      colors[sel.back].erase(sel);
    }
  }

  cout << endl;
}