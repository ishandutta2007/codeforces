#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool ask (int u, int v, int w) {
  cout << "? " << 1 + u << " " << 1 + v << " " << 1 + w << endl;

  int resp;
  cin >> resp;

  if (resp == -1) {
    exit(0);
  }

  return !resp;
}

void report (const vector<int> &ans) {
  cout << "! " << (int) ans.size();
  for (int u : ans) {
    cout << " " << 1 + u;
  }
  cout << endl;
}

const int MAX_N = 1e4 + 5;

bool major [MAX_N];
int status [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    status[i] = -1;
  }
  
  for (int i = 0; i < n / 3; i++) {
    major[i] = ask(3 * i, 3 * i + 1, 3 * i + 2);
  }

  // impostor block, ok block
  int u = -1, v = -1;
  for (int i = 0; i < n / 3; i++) {
    if (major[i]) {
      u = i;
    } else {
      v = i;
    }
  }

  assert(u != -1);
  assert(v != -1);

  int imp, ok;
  if (!ask(3 * u, 3 * u + 1, 3 * v)) {
    imp = 3 * u + 2;
    ok = 3 * v;
  } else if (!ask(3 * u, 3 * u + 1, 3 * v + 1)) {
    imp = 3 * u + 2;
    ok = 3 * v + 1;
  } else {
    // 3 * u and 3 * u + 1 are IMP
    status[3 * u] = 1;
    status[3 * u + 1] = 1;

    imp = 3 * u;
    if (ask(3 * v, 3 * v + 1, 3 * u)) {
      ok = 3 * v + 2;
    } else {
      status[3 * v] = 0;
      status[3 * v + 1] = 0;
      ok = 3 * v;
    }
  }
  status[ok] = 0;
  status[imp] = 1;

  for (int k = 0; k < 3; k++) {
    if (status[3 * u + k] == -1) {
      status[3 * u + k] = ask(ok, imp, 3 * u + k);
    }

    if (status[3 * v + k] == -1) {
      status[3 * v + k] = ask(ok, imp, 3 * v + k);
    }
  }
  
  for (int i = 0; i < n / 3; i++) {
    if (i == u || i == v) continue;

    if (major[i]) {
      // imp major
      if (ask(ok, 3 * i, 3 * i + 1)) {
        // 0 and 1 are impostors, ask about 2
        status[3 * i] = 1;
        status[3 * i + 1] = 1;
        status[3 * i + 2] = ask(imp, ok, 3 * i + 2);
      } else {
        // 0 xor 1 is ok, 2 is an impostor
        status[3 * i] = ask(imp, ok, 3 * i);
        status[3 * i + 1] = !status[3 * i];
        status[3 * i + 2] = 1;
      }
    } else {
      // ok major
      if (ask(imp, 3 * i, 3 * i + 1)) {
        // 0 xor 1 is an impostor , 2 is ok
        status[3 * i] = ask(imp, ok, 3 * i);
        status[3 * i + 1] = !status[3 * i];
        status[3 * i + 2] = 0;
      } else {
        // 0 and 1 are ok, ask about 2
        status[3 * i] = 0;
        status[3 * i + 1] = 0;
        status[3 * i + 2] = ask(imp, ok, 3 * i + 2);
      }
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (status[i]) {
      ans.push_back(i);
    }
  }

  report(ans);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}