#include <iostream>
#include <bitset>

typedef long long llong;

const int MAX_VERT = 505;
const int MAX_LG = 60;

using namespace std;

struct matrix {
  int height;
  bitset<MAX_VERT> *rows;

  matrix () {
  }

  matrix (int _height) {
    height = _height;
    
    rows = new bitset<MAX_VERT> [height];
    for (int i = 0; i < height; i++) {
      rows[i] = bitset<MAX_VERT> (0);
    }
  }

  void print () {
    for (int i = 0; i < height; i++) {
      cout << "|";
      for (int j = 0; j < height; j++) {
        cout << " " << rows[i][j];
      }
      cout << " |\n";
    }
  }
};

matrix operator* (matrix p, matrix q) {
  matrix ans (p.height);
  
  for (int i = 0; i < ans.height; i++) {
    for (int j = 0; j < ans.height; j++) {
      if (p.rows[i][j]) {
        ans.rows[i] |= q.rows[j];
      }
    }
  }

  return ans;
}

matrix pmat [MAX_LG], bmat [MAX_LG];

int main () {
  int vertexc, edgec;
  cin >> vertexc >> edgec;

  pmat[0] = matrix(vertexc);
  bmat[0] = matrix(vertexc);

  for (int i = 0; i < edgec; i++) {
    int u, v, type;
    cin >> u >> v >> type;

    if (type == 0) {
      pmat[0].rows[u - 1][v - 1] = true;
    } else {
      bmat[0].rows[u - 1][v - 1] = true;
    }
  }

  for (int i = 1; i < MAX_LG; i++) {
    pmat[i] = pmat[i - 1] * bmat[i - 1];
    bmat[i] = bmat[i - 1] * pmat[i - 1];
  }

  matrix cur (vertexc);
  for (int i = 0; i < vertexc; i++) {
    cur.rows[i][i] = true;
  }

  llong ans = 0, cur_t = 0;
  for (int i = MAX_LG - 1; i >= 0; i--) {
    matrix nxt;

    if (cur_t == 0) {
      nxt = cur * pmat[i];
    } else {
      nxt = cur * bmat[i];
    }

    if (nxt.rows[0].count() > 0) {
      cur = nxt;
      cur_t = !cur_t;
      ans += 1LL << i;
    }
  }

  cout << (ans > 1000000000000000000LL ? -1 : ans) << endl;
}