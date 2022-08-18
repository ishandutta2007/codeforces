#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
  char c;
  int pos;

  Pair (char _c = 0, int _pos = 0) :
    c(_c), pos(_pos) {}
};

bool operator< (Pair p, Pair q) {
  if (p.c != q.c) {
    return p.c > q.c;
  }
  return p.pos < q.pos;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  vector<Pair> ord (s.size());
  for (int i = 0; i < (int) s.size(); i++) {
    ord.push_back(Pair(s[i], i));
  }

  sort(ord.begin(), ord.end());

  int lastpos = -1;
  for (auto pr : ord) {
    if (pr.pos > lastpos) {
      cout << pr.c;
      lastpos = pr.pos;
    }
  }
  cout << endl;
}