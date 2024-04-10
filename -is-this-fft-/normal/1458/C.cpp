#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix transp (const Matrix &m) {
  int n = m.size();
  Matrix ans (n, vector<int> (n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans[j][i] = m[i][j];
    }
  }
  return ans;
}

vector<int> invert (const vector<int> &v) {
  int n = v.size();
  vector<int> ans (n);
  for (int i = 0; i < n; i++) {
    ans[v[i]] = i;
  }
  return ans;
}

Matrix hinv (const Matrix &m) {
  int n = m.size();
  Matrix ans (n);
  for (int i = 0; i < n; i++) {
    ans[i] = invert(m[i]);
  }
  return ans;
}

Matrix vinv (const Matrix &m) {
  Matrix cur = transp(m);
  cur = hinv(cur);
  cur = transp(cur);
  return cur;
}

enum Ops {
  hshift = 0,
  vshift = 1,
  add = 2
};

const int SC = 3;

typedef array<Ops, SC> Func;

const Func H = {add, vshift, hshift};
const Func V = {hshift, add, vshift};
const Func ID = {hshift, vshift, add};

Func comp (Func f, Func g) {
  Func ans;
  for (int i = 0; i < SC; i++) {
    ans[i] = f[g[i]];
  }
  return ans;
}

void solve () {
  int n, qc;
  cin >> n >> qc;

  Matrix M (n, vector<int> (n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> M[i][j];
      M[i][j]--;
    }
  }

  string ops;
  cin >> ops;

  reverse(ops.begin(), ops.end());

  int dx = 0, dy = 0, dz = 0;
  Func cur = ID;
  for (char c : ops) {
    if (c == 'I') {
      cur = comp(cur, H);
    } else if (c == 'C') {
      cur = comp(cur, V);
    } else {
      Ops base;
      if (c == 'L' || c == 'R') {
        base = hshift;
      } else {
        base = vshift;
      }

      int arg;
      if (c == 'R' || c == 'D') {
        arg = 1;
      } else {
        arg = -1;
      }

      base = cur[base];

      if (base == hshift) dx += arg;
      if (base == vshift) dy += arg;
      if (base == add) dz += arg;
    }
  }

  reverse(ops.begin(), ops.end());

  vector<char> invops;
  for (char c : ops) {
    if (c != 'I' && c != 'C') {
      continue;
    }

    if (!invops.empty() && c == invops.back()) {
      invops.pop_back();
    } else {
      invops.push_back(c);
    }
  }

  int invopc = (int) invops.size();
  invopc %= 6;

  for (int i = 0; i < invopc; i++) {
    if (invops[i] == 'I') {
      M = hinv(M);
    } else {
      M = vinv(M);
    }
  }

  dx %= n;
  dy %= n;
  dz %= n;

  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << M[i][j] + 1 << " ";
    }
    cout << endl;
  }
  cout << endl;
  
  */
  //  cout << invopc << " " << dx << " " << dy << " " << dz << endl;
  swap(dx, dy);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << (M[(i - dx + n) % n][(j - dy + n) % n] + dz + n) % n + 1 << " ";
    }
    cout << '\n';
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}