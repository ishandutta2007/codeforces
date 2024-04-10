#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<pair<int, int>, int> grundys;

int grundy (int num, int mask) {
  if (num == 0) {
    return 0;
  }

  set<int> cgrundy;
  for (int i = 1; i <= num; i++) {
    if (i > 31) {
      pair<int, int> nexts = make_pair(num - i, mask);
      if (grundys.find(nexts) == grundys.end()) {
        grundys[nexts] = grundy(nexts.first, nexts.second);
      }
      cgrundy.insert(grundys[nexts]);
    } else if (!(mask & 1 << (i - 1))) {
      pair<int, int> nexts = make_pair(num - i, (mask ^ 1 << (i - 1)));
      if (grundys.find(nexts) == grundys.end()) {
        grundys[nexts] = grundy(nexts.first, nexts.second);
      }
      cgrundy.insert(grundys[nexts]);
    }
  }

  for (int i = 0; i < 100; i++) {
    if (cgrundy.find(i) == cgrundy.end()) {
      return i;
    }
  }

  cout << "???" << endl;
}

int main () {
  vector<int> psize;
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= i; j++) {
      psize.push_back(i);
    }
  }

  int pilec, xors = 0;
  cin >> pilec;
  for (int i = 0; i < pilec; i++) {
    int pile;
    cin >> pile;

    xors ^= psize[pile];
  }

  if (xors == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}