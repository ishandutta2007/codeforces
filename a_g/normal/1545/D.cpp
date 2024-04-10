#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int m, k;
  cin >> m >> k;
  vector<long long> s1(k), s2(k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      s1[i] += x;
      s2[i] += 1LL*x*x;
    }
  }
  vector<long long> s1_diff(k-1);
  for (int i = 0; i < k-1; i++) {
    s1_diff[i] = s1[i+1]-s1[i];
  }
  long long expected_diff =
    (count(s1_diff.begin(), s1_diff.end(), s1_diff[0]) >
     count(s1_diff.begin(), s1_diff.end(), s1_diff[k-2])
     ? s1_diff[0] : s1_diff[k-2]);

  int index = -1;
  int delta = -1;
  int c = count(s1_diff.begin(), s1_diff.end(), expected_diff);
  if (c == k-2) {
    if (s1_diff[0] == expected_diff) {
      index = k-1;
      delta = s1_diff[k-2]-expected_diff;
    }
    else {
      index = 0;
      delta = expected_diff-s1_diff[0];
    }
  }
  else {
    assert(c == k-3);
    for (int i = 0; i < k-2; i++) {
      if (s1_diff[i] != expected_diff) {
        index = i+1;
        delta = s1[index]-(s1[index+1]+s1[index-1])/2;
        assert(s1_diff[i+1] != expected_diff);
        break;
      }
    }
  }
  assert(index != -1);

  long long delta2;
  if (index >= 3) {
    delta2 = s2[index]-3*s2[index-1]+3*s2[index-2]-s2[index-3];
  }
  else {
    assert(index+3 < k);
    delta2 = s2[index]-3*s2[index+1]+3*s2[index+2]-s2[index+3];
  }

  // (p+delta)^2-p^2 = delta2
  int p = (delta2-1LL*delta*delta)/(2*delta);
  cout << index << ' ' << p << '\n';
}