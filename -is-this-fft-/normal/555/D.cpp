#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 5;

int pos [MAX_N];
set<pair<int, int>> pegset;

int last_upto (int x) {
  return prev(pegset.upper_bound(make_pair(x, MAX_N)))->second;
}

int first_atleast (int x) {
  return pegset.lower_bound(make_pair(x, -1))->second;
}

struct state {
  int peg, len, side; // 0 if forward, 1 if backward
};

state naive_nxt (state s) {
  state ans;
  if (s.side == 0) {
    ans.peg = last_upto(pos[s.peg] + s.len);
  } else {
    ans.peg = first_atleast(pos[s.peg] - s.len);
  }

  ans.len = s.len - abs(pos[ans.peg] - pos[s.peg]);
  ans.side = !s.side;
  return ans;
}

state quick_nxt (state s) {
  state nxt = naive_nxt(s);
  state nxt_nxt = naive_nxt(nxt);
  if (nxt.peg == s.peg) {
    return nxt;
  }

  if (nxt_nxt.peg == s.peg) {
    int ldiff = s.len - nxt_nxt.len;
    if (ldiff != 0) {
      nxt_nxt.len %= ldiff;
    }
    return naive_nxt(nxt_nxt);
  } else {
    return nxt_nxt;
  }
}

bool accepting (state s) {
  state nxt = naive_nxt(s);
  state nxt_nxt = naive_nxt(nxt);

  return s.peg == nxt.peg && nxt.peg == nxt_nxt.peg;
}

void solve () {
  state cur;
  cin >> cur.peg >> cur.len;
  cur.side = 0;

  while (true) {
    cur = quick_nxt(cur);
    if (accepting(cur)) {
      cout << cur.peg << '\n';
      return;
    }
  }
}

int main () {
  int pegc, queryc;
  cin >> pegc >> queryc;

  for (int i = 1; i <= pegc; i++) {
    cin >> pos[i];
    pegset.insert(make_pair(pos[i], i));
  }

  for (int i = 0; i < queryc; i++) {
    solve();
  }
}