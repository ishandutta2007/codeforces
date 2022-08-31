#include <iostream>

using namespace std;

const int MAX_STUD = 100005;

bool vis [MAX_STUD];
int memo [MAX_STUD];

int query (int n) {
  if (vis[n]) {
    return memo[n];
  }

  vis[n] = 1;
  cout << "? " << n << endl;
  cin >> memo[n];

  return memo[n];
}

int studentc;

int opposite (int n) {
  if (n + studentc / 2 > studentc) {
    return n - studentc / 2;
  }
  return n + studentc / 2;
}

int cross (int a, int b, int c, int d) {
  return (a > c && b < d) || (a < c && b > d);
}

int ans;
void search (int l, int r) {
  int m = (l + r) / 2;
  if (query(m) == query(opposite(m))) {
    ans = m;
    return;
  }

  if (cross(query(l), query(m), query(opposite(l)), query(opposite(m)))) {
    search(l, m);
  } else {
    search(m, r);
  }
}
  

int main () {
  cin >> studentc;

  if (studentc % 4 != 0) {
    cout << "! -1" << endl;
    return 0;
  }

  if (query(1) == query(1 + studentc / 2)) {
    cout << "! 1" << endl;
    return 0;
  }

  search(1, 1 + studentc / 2);
  cout << "! " << ans << endl;
  return 0;
}