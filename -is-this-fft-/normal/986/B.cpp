#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class fenwick {
  vector<int> tree;
  int length;

public:
  fenwick (int _length) {
    length = _length;

    tree = vector<int> (length + 5, 0);
  }

  void add (int idx, int val) {
    for (int i = idx; i <= length; i += i & -i) {
      tree[i] += val;
    }
  }

  int get (int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }
};

int main () {
  int length;
  cin >> length;

  vector<pair<int, int>> perm (length);
  for (int i = 0; i < length; i++) {
    cin >> perm[i].first;
    perm[i].second = i + 1;
  }

  sort(perm.begin(), perm.end());

  fenwick counter (length);
  int inv_c = 0;
  for (int i = length - 1; i >= 0; i--) {
    inv_c += counter.get(perm[i].second);
    counter.add(perm[i].second, 1);
    inv_c %= 2;
  }

  if (inv_c == (3 * length) % 2) {
    cout << "Petr" << endl;
  } else {
    cout << "Um_nik" << endl;
  }
}