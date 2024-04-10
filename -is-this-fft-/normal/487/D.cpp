#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_W = 11;

int width;

struct Row {
  int lfend, rgend;
  pair<int, int> trans [MAX_W];

  pair<int, int> apply (int col) const {
    return trans[col];
  }

  pair<int, int> applyw (int row, int col) const {
    if (row != rgend) {
      return make_pair(row, col);
    } else {
      return apply(col);
    }
  }

  pair<int, int> applyw (pair<int, int> pr) const {
    return applyw(pr.first, pr.second);
  }
};

Row mul (const Row &l, const Row &r) {
  Row ans;
  ans.lfend = l.lfend;
  ans.rgend = r.rgend;

  for (int i = 1; i <= width; i++) {
    if (r.apply(i).first == l.rgend) {
      ans.trans[i] = l.apply(r.apply(i).second);
    } else {
      ans.trans[i] = r.apply(i);
    }
  }
  return ans;
}

Row whatever (int idx) {
  Row ans;
  ans.lfend = idx;
  ans.rgend = idx;
  return ans;
}

Row from_str (const string &line, int idx) {
  Row ans;
  ans.lfend = idx;
  ans.rgend = idx;

  for (int i = 1; i <= width; i++) {
    ans.trans[i] = make_pair(-1, -1);
  }

  for (int i = 1; i <= width; i++) {
    if (line[i - 1] == '<') {
      ans.trans[i] = make_pair(idx, 0);
    } else {
      break;
    }
  }

  for (int i = width; i >= 1; i--) {
    if (line[i - 1] == '>') {
      ans.trans[i] = make_pair(idx, width + 1);
    } else {
      break;
    }
  }

  for (int k = 1; k <= width; k++) {
    if (line[k - 1] == '^') {
      for (int i = k + 1; i <= width; i++) {
        if (line[i - 1] == '<') {
          ans.trans[i] = make_pair(idx - 1, k);
        } else {
          break;
        }
      }

      ans.trans[k] = make_pair(idx - 1, k);

      for (int i = k - 1; i >= 1; i--) {
        if (line[i - 1] == '>') {
          ans.trans[i] = make_pair(idx - 1, k);
        } else {
          break;
        }
      }
    }
  }

  return ans;
}

const int MAX_N = 1 << 17;

string lines [MAX_N];
Row tree [2 * MAX_N];
int length;

void update (int idx) {
  if (idx == 0) return;
  tree[idx] = mul(tree[2 * idx], tree[2 * idx + 1]);
  update(idx / 2);
}

void set_row (int i, int j, char c) {
  lines[i][j - 1] = c;
  tree[MAX_N + i] = from_str(lines[i], i);
  update((MAX_N + i) / 2);
}

void build () {
  tree[MAX_N] = whatever(0);
  for (int i = 1; i <= length; i++) {
    tree[MAX_N + i] = from_str(lines[i], i);
  }
  for (int i = length + 1; i < MAX_N; i++) {
    tree[MAX_N + i] = whatever(i);
  }

  for (int i = MAX_N - 1; i >= 1; i--) {
    tree[i] = mul(tree[2 * i], tree[2 * i + 1]);
  }
}

pair<int, int> query (int ql, int qr, pair<int, int> cur) {
  while (qr >= ql) {
    int k = MAX_N + qr;
    while (tree[k / 2].lfend >= ql && tree[k / 2].rgend == qr) {
      k /= 2;
    }
    cur = tree[k].applyw(cur);
    qr = tree[k].lfend - 1;
  }
  return cur;
}

ostream& operator<< (ostream &out, pair<int, int> pr) {
  out << "(" << pr.first << " " << pr.second << ")";
  return out;
}

int main () {
  ios::sync_with_stdio(false);

  int queryc;
  cin >> length >> width >> queryc;

  for (int i = 1; i <= length; i++) {
    cin >> lines[i];
  }

  build();

  /*
  for (int i = 1; i <= length; i++) {
    for (int j = 1; j <= width; j++) {
      cout << tree[MAX_N + i].trans[j] << " ";
    }
    cout << endl;
  }
  */
  
  for (int i = 0; i < queryc; i++) {
    char type;
    cin >> type;

    if (type == 'A') {
      int row, col;
      cin >> row >> col;
      
      pair<int, int> ans = query(1, row, make_pair(row, col));
      cout << ans.first << " " << ans.second << '\n';
    } else {
      int row, col;
      char c;
      cin >> row >> col >> c;

      set_row(row, col, c);
    }
  }
}