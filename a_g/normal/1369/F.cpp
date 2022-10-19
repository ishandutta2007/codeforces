#include <bits/stdc++.h>
using namespace std;

bool first_win(long long s, long long e) {
  if (e&1 || 2*s > e) {
    return (e-s)&1;
  }
  if (4*s > e) {
    return 1;
  }
  return first_win(s, e/4);
}

bool first_lose(long long s, long long e) {
  if (2*s > e) {
    return 1;
  }
  return first_win(s, e/2);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  vector<int> masks(t);

  for (int i = 0; i < t; i++) {
    long long s, e;
    cin >> s >> e;
    if (first_win(s, e)) masks[i] ^= 2;
    if (first_lose(s, e)) masks[i] ^= 1;
  }

  for (int g: {0, 1}) {
    int valid = 1<<g;
    for (int i = t-1; i >= 0; i--) {
      int newv = 0;
      if (masks[i]&2 && valid&1) newv |= 2;
      if (masks[i]&1 && valid&2) newv |= 2;
      if (!(masks[i]&2) && valid&1) newv |= 1;
      if (!(masks[i]&1) && valid&2) newv |= 1;
      valid = newv;
    }
    cout << (valid>>1) << ' ';
  }
  cout << '\n';
}