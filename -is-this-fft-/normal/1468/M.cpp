#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 5;
const int BLOCK = 300;

int cur_age;
int _age [MAX_N];
int _garr [MAX_N];
int &garr (int idx) {
  if (_age[idx] != cur_age) {
    _age[idx] = cur_age;
    _garr[idx] = 0;
  }
  return _garr[idx];
}

void reset () {
  cur_age++;
}

vector<int> sets [MAX_N];
vector<int> inb [MAX_N];
vector<pair<int, int>> bucket [MAX_N];

void solve () {
  int n;
  cin >> n;

  map<int, int> compr;
  for (int i = 1; i <= n; i++) {
    sets[i].clear();

    int k;
    cin >> k;

    sets[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> sets[i][j];
      compr[sets[i][j]] = 0;
    }
  }

  int difc = 0;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = difc;
    inb[difc].clear();
    bucket[difc].clear();
    difc++;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int) sets[i].size(); j++) {
      sets[i][j] = compr[sets[i][j]];
    }
  }

  // small-big
  for (int i = 1; i <= n; i++) {
    if (sets[i].size() < BLOCK) {
      continue;
    }

    reset();
    for (int u : sets[i]) {
      garr(u) = 1;
    }

    for (int j = 1; j <= n; j++) {
      if (sets[j].size() >= BLOCK) {
        continue;
      }

      int matchc = 0;
      for (int u : sets[j]) {
        if (garr(u)) {
          matchc++;
        }
      }

      if (matchc >= 2) {
        cout << i << " " << j << '\n';
        return;
      }
    }
  }

  // big-big
  for (int i = 1; i <= n; i++) {
    if (sets[i].size() < BLOCK) {
      continue;
    }

    for (int u : sets[i]) {
      inb[u].push_back(i);
    }
  }

  set<pair<int, int>> seen;
  for (int i = 0; i < difc; i++) {
    for (int j = 0; j < (int) inb[i].size(); j++) {
      for (int k = j + 1; k < (int) inb[i].size(); k++) {
        int u = inb[i][j];
        int v = inb[i][k];

        if (seen.count(make_pair(u, v))) {
          cout << u << " " << v << '\n';
          return;
        }
        seen.insert(make_pair(u, v));
      }
    }
  }

  // small-small
  for (int i = 1; i <= n; i++) {
    if (sets[i].size() >= BLOCK) {
      continue;
    }

    for (int j = 0; j < (int) sets[i].size(); j++) {
      for (int k = j + 1; k < (int) sets[i].size(); k++) {
        int a = sets[i][j];
        int b = sets[i][k];

        if (a > b) {
          swap(a, b);
        }
        bucket[a].push_back(make_pair(b, i));
      }
    }
  }

  for (int a = 0; a < difc; a++) {
    reset();
    for (auto pr : bucket[a]) {
      if (garr(pr.first) != 0) {
        cout << garr(pr.first) << " " << pr.second << '\n';
        return;
      }
      garr(pr.first) = pr.second;
    }
  }

  cout << -1 << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}