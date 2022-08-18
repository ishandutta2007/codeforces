#include <iostream>
#include <stdlib.h>
#include <set>
#include <vector>

using namespace std;

bool is_good (vector<int> v) {
  set<int> sums;
  int n = v.size();

  int tot = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      sums.insert(v[i] + v[j]);
      tot++;
    }
  }

  return (int) sums.size() == tot;
}

const int TRIES = 50;

vector<int> gen_good (int n, int cap) {
  if (n == 0) return vector<int> (0);

  while (true) {
    vector<int> w = gen_good(n - 1, cap);
    for (int i = 0; i < TRIES; i++) {
      w.push_back(rand() % cap);
      if (is_good(w)) {
        return w;
      }
      w.pop_back();
    }
  }
}

int MAGIC [] = {305, 82, 166, 316, 484, 97, 373, 210, 84, 9, 173,
                218, 470, 288, 493, 144, 21, 337, 474, 475};

int main () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        cout << 0 << ' ';
      } else {
        cout << MAGIC[i] + MAGIC[j] << ' ';
      }
    }
    cout << '\n';
  }
}