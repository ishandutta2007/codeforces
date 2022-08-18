#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve () {
  int n, K;
  ll x;
  cin >> n >> K >> x;
  x--;

  string s;
  cin >> s;

  // -1 = a, j - a star complex consisting of j stars
  vector<int> blocks;
  for (char c : s) {
    if (c == 'a') {
      blocks.push_back(-1);
    } else {
      if (blocks.empty() || blocks.back() == -1) {
        blocks.push_back(0);
      }
      blocks.back()++;
    }
  }

  reverse(blocks.begin(), blocks.end());

  // -1 = a, j - j times b
  vector<int> ans;
  for (int b : blocks) {
    if (b == -1) {
      ans.push_back(-1);
    } else {
      int choices = b * K + 1;
      ans.push_back(x % choices);
      x /= choices;
    }
  }

  reverse(ans.begin(), ans.end());

  for (int b : ans) {
    if (b == -1) {
      cout << 'a';
    } else {
      for (int j = 0; j < b; j++) {
        cout << 'b';
      }
    }
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}