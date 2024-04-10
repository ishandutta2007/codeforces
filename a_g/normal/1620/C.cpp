#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    ll x;
    cin >> n >> k >> x;
    x--;

    string s;
    cin >> s;
    vector<int> blocks;
    int count = 0;
    for (char c: s) {
      if (c == 'a') {
        if (count) blocks.push_back(k*count+1);
        count = 0;
      }
      else {
        count++;
      }
    }
    if (count) blocks.push_back(k*count+1);
    int m = blocks.size();
    vector<int> t(m);
    for (int i = m-1; i >= 0; i--) {
      t[i] = x % blocks[i];
      x /= blocks[i];
    }

    int index = 0;
    bool blockmade = 0;
    for (char c: s) {
      if (c == 'a') {
        if (blockmade) {
          cout << string(t[index], 'b');
          index++;
          blockmade = 0;
        }
        cout << 'a';
      }
      else {
        blockmade = 1;
      }
    }
    if (blockmade) cout << string(t[index], 'b');
    cout << '\n';
  }
}