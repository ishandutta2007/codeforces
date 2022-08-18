#include <iostream>
#include <vector>

using namespace std;

int ask () {
  int x;
  cin >> x;

  return x;
}

void put (int b, pair<int, int> p) {
  cout << b << " " << p.first << " " << p.second << endl;
}

int main () {
  int n;
  cin >> n;

  vector<pair<int, int>> A, B;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i + j) % 2 == 0) {
        A.push_back(make_pair(i, j));
      } else {
        B.push_back(make_pair(i, j));
      }
    }
  }

  for (int i = 0; i < n * n; i++) {
    int forb = ask();
    if (!A.empty() && !B.empty()) {
      if (forb == 1) {
        auto p = B.back();
        B.pop_back();
        put(2, p);
      } else {
        auto p = A.back();
        A.pop_back();
        put(1, p);
      }
    } else if (!A.empty()) {
      auto p = A.back();
      A.pop_back();
      if (forb == 1) {
        put(3, p);
      } else {
        put(1, p);
      }
    } else if (!B.empty()) {
      auto p = B.back();
      B.pop_back();
      if (forb == 2) {
        put(3, p);
      } else {
        put(2, p);
      }
    }
  }
}