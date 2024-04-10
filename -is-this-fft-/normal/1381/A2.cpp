#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Reversible {
  deque<int> c;
  int rev; // is it reversed and flipped
public:
  Reversible (deque<int> _c, int _rev = 0) :
    c(_c), rev(_rev) {}
  
  void reverse () {
    rev = !rev;
  }

  int front () {
    if (!rev) return c[0];
    else return !c.back();
  }

  int back () {
    if (!rev) return c.back();
    else return !c[0];
  }

  void flip_front () {
    if (!rev) c[0] = !c[0];
    else c.back() = !c.back();
  }

  void pop_back () {
    if (!rev) c.pop_back();
    else c.pop_front();
  }
};

void solve () {
  int n;
  cin >> n;

  deque<int> s (n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    s[i] = c - '0';
  }

  vector<int> t (n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    t[i] = c - '0';
  }

  Reversible R (s);
  vector<int> ans;
  for (int i = n - 1; i > 0; i--) {
    if (R.back() != t[i]) {
      if (R.front() != t[i]) {
        ans.push_back(i + 1);
        R.reverse();
      } else {
        ans.push_back(1);
        R.flip_front();
        ans.push_back(i + 1);
        R.reverse();
      }
    }
    
    R.pop_back();
  }

  if (R.back() != t[0]) {
    ans.push_back(1);
    R.reverse();
  }

  cout << (int) ans.size();
  for (int u : ans) {
    cout << " " << u;
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