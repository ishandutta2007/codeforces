#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> odds;
  vector<pair<int, int>> evens;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i+j)&1) odds.emplace_back(i, j);
      else evens.emplace_back(i, j);
    }
  }
  // put 1 in odds, 2 in evens
  int op = 0;
  int ep = 0;
  int turns = n*n;
  while (turns--) {
    int a;
    cin >> a;
    if (op == odds.size()) {
      int b = (a == 2 ? 3 : 2);
      cout << b << " " << evens[ep].first << " " << evens[ep].second << endl;
      ep++;
    }
    else if (ep == evens.size()) {
      int b = (a == 1 ? 3 : 1);
      cout << b << " " << odds[op].first << " " << odds[op].second << endl;
      op++;
    }
    else if (a != 1) {
      int b = 1;
      cout << b << " " << odds[op].first << " " << odds[op].second << endl;
      op++;
    }
    else {
      int b = 2;
      cout << b << " " << evens[ep].first << " " << evens[ep].second << endl;
      ep++;
    }
  }
}