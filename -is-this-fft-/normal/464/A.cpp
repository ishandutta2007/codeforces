#include <iostream>
#include <string>
#include <set>

using namespace std;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

bool problem (int pos, string &s) {
  if (pos - 1 >= 0 && s[pos] == s[pos - 1]) return true;
  if (pos - 2 >= 0 && s[pos] == s[pos - 2]) return true;
  return false;
}

char nxt (int pos, string &s, int P) {
  set<char> cands;
  for (int i = 0; i < min(3, P); i++) {
    cands.insert('a' + i);
  }

  if (pos - 1 >= 0) cands.erase(s[pos - 1]);
  if (pos - 2 >= 0) cands.erase(s[pos - 2]);
  if (cands.empty()) failure();
  return *cands.begin();
}

void sfx (int pos, string &s, int P) {
  if (pos == (int) s.size()) return;
  s[pos] = nxt(pos, s, P);
  sfx(pos + 1, s, P);
}

void add (int pos, string &s, int P, bool force = false) {
  if (pos < 0) failure();

  if (force) {
    s[pos]++;
  }
  while (problem(pos, s) && s[pos] < 'a' + P) {
    s[pos]++;
  }

  if (s[pos] == 'a' + P) {
    add(pos - 1, s, P, true);
  } else {
    sfx(pos + 1, s, P);
  }
}

int main () {
  int n, P;
  cin >> n >> P;

  string s;
  cin >> s;

  add((int) s.size() - 1, s, P, true);
  for (int i = (int) s.size() - 1; i >= 0; i--) {
    if (problem(i, s)) {
      add(i, s, P);
    }
  }

  cout << s << endl;
}