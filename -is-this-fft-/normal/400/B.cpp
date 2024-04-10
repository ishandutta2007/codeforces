#include <iostream>
#include <set>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

int main () {
  int n, m;
  cin >> n >> m;

  set<int> S;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    int gp = -1, sp = -1;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'G') {
        gp = j;
      } else if (s[j] == 'S') {
        sp = j;
      }
    }

    S.insert(sp - gp);
    if (sp < gp) {
      failure();
    }
  }

  cout << (int) S.size() << endl;
}