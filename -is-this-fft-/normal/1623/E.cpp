#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 5;

char at [MAX_N];
int l [MAX_N];
int r [MAX_N];

int K;
string s;
int id [MAX_N];
void builds (int u) {
  if (l[u] != 0) {
    builds(l[u]);
  }

  id[u] = s.size();
  s += at[u];

  if (r[u] != 0) {
    builds(r[u]);
  }
}

char nxtd [MAX_N];
bool dup [MAX_N];

bool calc (int u, int d, int ld) {
  bool res = false;
  if (l[u] != 0) {
    res = calc(l[u], d + 1, ld);
  }

  if (res) {
    dup[id[u]] = true;
  } else if (nxtd[id[u]] > s[id[u]] && d - ld <= K) {
    K -= d - ld;
    dup[id[u]] = true;
  }

  if (dup[id[u]] && r[u] != 0) {
    calc(r[u], d + 1, d);
  }

  return dup[id[u]];
}

void print (int u) {
  if (l[u]) {
    print(l[u]);
  }

  cout << s[id[u]];
  if (dup[id[u]]) {
    cout << s[id[u]];
  }

  if (r[u]) {
    print(r[u]);
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n >> K;

  for (int i = 1; i <= n; i++) {
    cin >> at[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }

  builds(1);
  
  nxtd[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == s[i + 1]) {
      nxtd[i] = nxtd[i + 1];
    } else {
      nxtd[i] = s[i + 1];
    }
  }

  calc(1, 1, 0);
  print(1);
  cout << endl;
}