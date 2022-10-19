#include <bits/stdc++.h>
using namespace std;

int used = 0;

bool query(vector<int>& a) {
  used++;
  assert(used <= 82);
  cout << "? " << a.size();
  for (int x: a) cout << ' ' << x;
  cout << endl;
  string ans;
  cin >> ans;
  return ans == "YES";
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> candidates(n);
  iota(candidates.begin(), candidates.end(), 1);
  while ((int)candidates.size() > 2) {
    vector<int> a, b;
    for (int i = 0; i < (int)candidates.size(); i++) {
      if (i&1) a.push_back(candidates[i]);
      if (i&2) b.push_back(candidates[i]);
    }
    bool x = query(a);
    bool y = query(b);
    bool z = query(b);
    bool w = query(a);
    vector<int> new_candidates;
    if (y == z) {
      if (y) {
        candidates = b;
      }
      else {
        for (int i = 0; i < (int)candidates.size(); i++) {
          if (!(i&2)) new_candidates.push_back(candidates[i]);
        }
        candidates = new_candidates;
      }
      continue;
    }
    int k1 = 2*y+w;
    int k2 = 2*z+x;
    for (int i = 0; i < (int)candidates.size(); i++) {
      if (i%4 == k1 || i%4 == k2) new_candidates.push_back(candidates[i]);
    }
    candidates = new_candidates;
  }
  for (int x: candidates) {
    cout << "! " << x << endl;
    string ans;
    cin >> ans;
    if (ans == ":)") return 0;
  }
  assert(0);
}