#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_SUB = 50;
const int SMALL = 1e6;

int possible [MAX_SUB];
vector<int> comb [MAX_SUB];
vector<int> subs [10];
bool memo_imp [SMALL];

vector<ll> solveFor (ll x) {
  // cout << "solving for " << x << endl;
  if (x < 0) {
    return {-1, -1, -1, -1, -1, -1};
  }

  if (x == 0) {
    return {0, 0, 0, 0, 0, 0};
  }

  if (x < SMALL && memo_imp[x]) {
    return {-1, -1, -1, -1, -1, -1};
  }

  for (int sub : subs[x % 10]) {
    if (x - sub >= 0) {
      vector<ll> resp = solveFor((x - sub) / 10);
      if (resp[0] != -1) {
        for (int i = 0; i < 6; i++) {
          resp[i] *= 10;
          resp[i] += comb[sub][i];
        }
        return resp;
      }
    }
  }

  if (x < SMALL) {
    memo_imp[x] = 1;
  }
  return {-1, -1, -1, -1, -1, -1};
}

void solve () {
  ll x;
  cin >> x;

  vector<ll> ans = solveFor(x);

  if (ans[0] == -1) {
    cout << -1 << '\n';
  } else {
    for (ll u : ans) {
      cout << u << ' ';
    }
    cout << '\n';
  }
}

int main () {
  vector<int> l = {0, 4, 7};
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
          for (int e = 0; e < 3; e++) {
            for (int f = 0; f < 3; f++) {
              comb[l[a] + l[b] + l[c] + l[d] + l[e] + l[f]] = {l[a], l[b], l[c], l[d], l[e], l[f]};
              possible[l[a] + l[b] + l[c] + l[d] + l[e] + l[f]] = 1;
            }
          }
        }
      }
    }
  }

  for (int i = 0; i < MAX_SUB; i++) {
    if (possible[i]) {
      subs[i % 10].push_back(i);
    }
  }

  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}