#include <iostream>
#include <vector>

using namespace std;

char maj (const string &s) {
  int zc = 0, oc = 0;
  for (char c : s) {
    if (c == '0') {
      zc++;
    } else {
      oc++;
    }
  }

  if (zc >= oc) return '0';
  return '1';
}

vector<int> list_pos (const string &s, char a) {
  vector<int> ans;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == a) {
      ans.push_back(i);
    }
  }
  return ans;
}

void solve () {
  int n;
  cin >> n;

  string a, b, c;
  cin >> a >> b >> c;

  int ma = maj(a);
  int mb = maj(b);
  int mc = maj(c);

  string s, t;
  if (ma == mb) {
    s = a;
    t = b;
  } else if (ma == mc) {
    s = a;
    t = c;
  } else {
    s = b;
    t = c;
  }

  char mj = maj(s);
  vector<int> spos = list_pos(s, mj);
  while ((int) spos.size() > n) spos.pop_back();
  vector<int> tpos = list_pos(t, mj);
  while ((int) tpos.size() > n) tpos.pop_back();

  int sptr = 0, tptr = 0, cptr = 0;
  while (sptr < 2 * n || tptr < 2 * n) {
    if (cptr < n && sptr == spos[cptr] && tptr == tpos[cptr]) {
      cout << mj;
      sptr++;
      tptr++;
      cptr++;
    } else if (sptr < 2 * n && !(cptr < n && sptr == spos[cptr])) {
      cout << s[sptr];
      sptr++;
    } else if (tptr < 2 * n && !(cptr < n && tptr == tpos[cptr])) {
      cout << t[tptr];
      tptr++;
    }
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