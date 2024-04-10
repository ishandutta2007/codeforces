#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 205;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

ll lcm (ll p, ll q) {
  p /= gcd(p, q);
  return p * q;
}

ll cyclcm = 1;

int nxt [MAX_N];

int vis [MAX_N];
int lvl [MAX_N];

bool in_cycle [MAX_N];

void find_cycle (int u, vector<int> &stk) {
  if (vis[u] == 1) {
    int cyclen = 1;
    while (stk.back() != u) {
      in_cycle[stk.back()] = true;
      stk.pop_back();
      cyclen++;
    }

    cyclcm = lcm(cyclcm, cyclen);
    in_cycle[u] = true;
  } else if (vis[u] == 2) {
    return;
  } else {
    vis[u] = 1;
    stk.push_back(u);
    find_cycle(nxt[u], stk);
    vis[u] = 2;
    if (!in_cycle[u]) {
      lvl[u] = lvl[nxt[u]] + 1;
    }
  }
}

int main () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      vector<int> stk;
      find_cycle(i, stk);
    }
  }

  ll mxl = 0;
  for (int i = 1; i <= n; i++) {
    mxl = max(mxl, (ll) lvl[i]);
  }

  if (mxl % cyclcm != 0) {
    mxl += ((cyclcm - mxl) % cyclcm + cyclcm) % cyclcm;
  }

  if (mxl == 0) {
    mxl += cyclcm;
  }
  
  cout << mxl << endl;
}