#include <iostream>
#include <set>
#include <vector>

using namespace std;

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

const int MAX_N = 1e5 + 5;

int genre [MAX_N];

int get_smallest_after (const set<int> &rem, int idx) {
  auto it = rem.upper_bound(idx);
  if (it == rem.end()) {
    return *rem.begin();
  }
  return *it;
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> genre[i];
  }

  set<int> cur; // indices of the current playlist
  set<int> rem; // indices of things that have a coprime to its left

  for (int i = 0; i < n; i++) {
    cur.insert(i);
  }

  for (int i = 1; i < n; i++) {
    if (gcd(genre[i - 1], genre[i]) == 1) {
      rem.insert(i);
    }
  }
  if (gcd(genre[n - 1], genre[0]) == 1) {
    rem.insert(0);
  }

  vector<int> ans;
  int last = 0;
  while (!rem.empty()) {
    int to_del = get_smallest_after(rem, last);
    int nxt = get_smallest_after(cur, to_del);

    rem.erase(to_del);
    cur.erase(to_del);
    
    if (cur.size() > 0) {
      rem.erase(nxt);

      auto it = cur.find(nxt);
      int prv;
      if (it == cur.begin()) {
        prv = *prev(cur.end());
      } else {
        prv = *prev(it);
      }
    
      if (gcd(genre[prv], genre[nxt]) == 1) {
        rem.insert(nxt);
      }
    }
    
    ans.push_back(to_del);
    last = nxt;
  }

  cout << (int) ans.size() << " ";
  for (int u : ans) {
    cout << 1 + u << " ";
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