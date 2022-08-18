#include <iostream>
#include <vector>

using namespace std;

pair<int, int> ask (vector<int> v) {
  cout << "?";
  for (int u : v) {
    cout << " " << u;
  }
  cout << endl;

  int pos, val;
  cin >> pos >> val;
  return {pos, val};
}

vector<int> kwo (int k, int idx) {
  vector<int> ans;
  for (int i = 1; i <= k; i++) {
    if (i != idx) {
      ans.push_back(i);
    }
  }
  return ans;
}

const int MAX_N = 505;

int side [MAX_N]; // same side as k+1-th?

int main () {
  int n, k;
  cin >> n >> k;

  if (k == 1) {
    cout << "! 1" << endl;
    return 0;
  }

  side[k + 1] = 1;
  pair<int, int> firstk = ask(kwo(k + 1, k + 1));
  int magic = firstk.first;
  for (int i = 1; i <= k; i++) {
    if (i != magic) {
      pair<int, int> cur = ask(kwo(k + 1, i));
      side[i] = cur.first == magic;
    }
  }

  int zc = 0, oc = 0;
  for (int i = 1; i <= k; i++) {
    if (i != magic) {
      if (side[i] == 0) zc++;
      else oc++;
    }
  }

  pair<int, int> wom = ask(kwo(k + 1, magic));
  if ((wom.second < firstk.second) ^ (side[wom.first] == 0)) {
    cout << "! " << oc + 1 << endl;
  } else {
    cout << "! " << zc + 1 << endl;
  }
}