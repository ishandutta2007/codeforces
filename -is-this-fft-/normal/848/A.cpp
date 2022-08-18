#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pairc (int n) {
  return (n * (n - 1)) / 2;
}

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  if (n == 0) {
    cout << 'a' << endl;
    return 0;
  }
  
  vector<pair<int, int>> opts;
  for (int i = 2; i < 1e3; i++) {
    opts.push_back(make_pair(i, pairc(i)));
  }

  char cur = 'a';
  while (!opts.empty()) {
    if (opts.back().second > n) {
      opts.pop_back();
    } else {
      n -= opts.back().second;
      for (int i = 0; i < opts.back().first; i++) {
        cout << cur;
      }
      cur++;
    }
  }

  cout << '\n';
}