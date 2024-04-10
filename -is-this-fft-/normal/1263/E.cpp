#include <iostream>

using namespace std;

const int MAX_N = 1 << 20;

struct State {
  int ld, rd, cur, mx;
};

State merge (State l, State r) {
  State ans;
  if (l.rd > r.ld) {
    ans.ld = l.ld;
    ans.rd = l.rd - r.ld + r.rd;
  } else {
    ans.ld = l.ld + r.ld - l.rd;
    ans.rd = r.rd;
  }
  ans.cur = l.cur + r.cur;
  ans.mx = max(l.mx, l.cur + r.mx);
  return ans;
}

State tree [2 * MAX_N];

void update (int idx) {
  if (idx == 0) return;
  tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
  update(idx / 2);
}

void set_char (int idx, char c) {
  tree[MAX_N + idx].ld = 0;
  tree[MAX_N + idx].rd = 0;
  tree[MAX_N + idx].mx = 0;
  tree[MAX_N + idx].cur = 0;
  if (c == '(') {
    tree[MAX_N + idx].rd = 1;
    tree[MAX_N + idx].mx = 1;
    tree[MAX_N + idx].cur = 1;
  } else if (c == ')') {
    tree[MAX_N + idx].ld = 1;
    tree[MAX_N + idx].mx = -1;
    tree[MAX_N + idx].cur = -1;
  }

  update((MAX_N + idx) / 2);
}

int main () {
  int queryc;
  cin >> queryc;

  string input;
  cin >> input;
  int pos = 0;
  for (char c : input) {
    if (c == 'L') {
      pos = max(0, pos - 1);
    } else if (c == 'R') {
      pos++;
    } else {
      set_char(pos, c);
    }

    if (tree[1].ld == 0 && tree[1].rd == 0) {
      cout << tree[1].mx << " ";
    } else {
      cout << -1 << " ";
    }
  }
  cout << endl;
}