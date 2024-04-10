#include <iostream>
#include <vector>

using namespace std;

vector<int> ask (int l, int r) {
  cout << "? " << l << " " << r << endl;

  vector<int> resp (r - l + 1);
  for (int i = 0; i < (int) resp.size(); i++) {
    cin >> resp[i];
    if (resp[i] == -1) {
      exit(0);
    }
  }

  return resp;
}

void report (int x) {
  cout << "! " << x << endl;
}

bool is_in (int l, int r) {
  auto vec = ask(l, r);
  int outc = 0;
  for (int u : vec) {
    if (u < l || r < u) {
      outc++;
    }
  }

  return ((int) vec.size() - outc) % 2; 
}

void search (int l, int r) {
  if (l == r) {
    report(l);
    return;
  }

  int m = (l + r) / 2;
  if (is_in(l, m)) {
    search(l, m);
  } else {
    search(m + 1, r);
  }
}

void solve () {
  int n;
  cin >> n;

  if (n == -1) {
    exit(0);
  }

  search(1, n);
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}