#include <iostream>
#include <string>

using namespace std;

string text, pattern;

bool is_occ (int idx) {
  if (idx + (int) pattern.size() > (int) text.size()) {
    return false;
  }
  
  for (int i = 0; i < (int) pattern.size(); i++) {
    if (text[idx + i] != pattern[i]) {
      return false;
    }
  }

  return true;
}

const int MAX_L = 1005;

int cnt [MAX_L];

int range (int l, int r) {
  if (r < l) {
    return 0;
  } else if (l == 0) {
    return cnt[r];
  } else {
    return cnt[r] - cnt[l - 1];
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int tl, pl, queryc;
  cin >> tl >> pl >> queryc;

  cin >> text >> pattern;

  for (int i = 0; i < (int) text.size(); i++) {
    cnt[i] = is_occ(i);
  }

  for (int i = 1; i < (int) text.size(); i++) {
    cnt[i] += cnt[i - 1];
  }

  for (int i = 0; i < queryc; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    cout << range(l, r - (int) pattern.size() + 1) << '\n';
  }
}